//
//  ResourceLoader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "ResourceLoader.hpp"
#include <GL/glew.h>
#include "Util.hpp"
#include <sstream>

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
    res.AddVertices(vertices, indices);
    
    return res;
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
