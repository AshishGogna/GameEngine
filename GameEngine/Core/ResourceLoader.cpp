//
//  ResourceLoader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "ResourceLoader.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Util.hpp"
#include <sstream>
#include <cstdio>

std::string ResourceLoader::LoadShader(std::string filePath)
{
    std::string shaderCode;
    
    std::ifstream shaderStream;
    shaderStream.open(filePath.c_str(), std::ios::in);
    if(shaderStream.is_open())
    {
        std::string line = "";
        while(getline(shaderStream, line))
        {
            shaderCode += "\n" + line;
        }
        shaderStream.close();
    }
    else
    {
        Util::Print("Unable to open " + filePath);
        Util::Exit();
    }

    return shaderCode;
}

Mesh ResourceLoader::LoadMesh(std::string filePath)
{
    std::string ext = filePath.substr(filePath.find_last_of(".") + 1);
    
    if(ext != "obj")
    {
        Util::Print("Error: File format not supported for mesh data: " + ext);
        Util::Exit();
    }
    
    vector<Vertex> vertices;
    vector<int> indices;
    
    std::ifstream shaderStream;
    shaderStream.open(filePath.c_str(), std::ios::in);
    if(shaderStream.is_open())
    {
        std::string line = "";
        while(getline(shaderStream, line))
        {
            vector<std::string> tokens = Split(line, ' ');
            
            if (tokens.size()==0 || tokens[0]=="#") {
                continue;
            }
            else if (tokens[0] == "v")
            {
                vertices.push_back(Vertex(Vector3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3]))));
            }
            else if (tokens[0] == "f")
            {
                indices.push_back(stoi(Split(tokens[1], '/')[0]) - 1);
                indices.push_back(stoi(Split(tokens[2], '/')[0]) - 1);
                indices.push_back(stoi(Split(tokens[3], '/')[0]) - 1);
                
                if (tokens.size() > 4)
                {
                    indices.push_back(stoi(Split(tokens[1], '/')[0]) - 1);
                    indices.push_back(stoi(Split(tokens[3], '/')[0]) - 1);
                    indices.push_back(stoi(Split(tokens[4], '/')[0]) - 1);
                }
            }
        }
        
        shaderStream.close();
    }
    else
    {
        Util::Print("Unable to open " + filePath);
        Util::Exit();
    }

    Mesh res = Mesh();
    res.AddVertices(vertices, indices, true);
    
    return res;
}

Texture ResourceLoader::LoadTexture(std::string filePath)
{
    std::string ext = filePath.substr(filePath.find_last_of(".") + 1);
    
    /*
    if(ext != "tga")
    {
        Util::Print("Error: File format not supported for mesh data: " + ext);
        Util::Exit();
    }
    */

    // Data read from the header of the BMP file
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
    // Actual RGB data
    unsigned char * data;
    
    FILE * file = fopen(filePath.c_str(), "rb");
    if (!file){printf("Image could not be opened\n"); return 0;}
    
    if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        return false;
    }
    
    if ( header[0]!='B' || header[1]!='M' ){
        printf("Not a correct BMP file\n");
        return 0;
    }
    
    dataPos    = *(int*)&(header[0x0A]);
    imageSize  = *(int*)&(header[0x22]);
    width      = *(int*)&(header[0x12]);
    height     = *(int*)&(header[0x16]);
    
    if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos==0)      dataPos=54; // The BMP header is done that way
    
    // Create a buffer
    data = new unsigned char [imageSize];
    
    // Read the actual data from the file into the buffer
    fread(data,1,imageSize,file);
    
    //Everything is in memory now, the file can be closed
    fclose(file);
    
    GLuint textureID;
    glGenTextures(1, &textureID);
    
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    return textureID;
}

vector<string> ResourceLoader::Split(std::string txt, char ch)
{
    vector<std::string> strs;
    unsigned int pos = (int)txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();
    
    // Decompose statement
    while( pos != (int)std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos  ) );
        initialPos = pos + 1;
        
        pos = (int)txt.find( ch, initialPos );
    }
    
    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min<unsigned int>( pos, (int)txt.size() ) - initialPos + 1 ) );
    
    return strs;
}

/*
void split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
}
 */
