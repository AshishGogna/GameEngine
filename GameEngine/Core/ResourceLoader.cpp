//
//  ResourceLoader.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "ResourceLoader.hpp"
#include <GL/glew.h>

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
        //std::cerr << "Error: " << strerror(errno);
        std::cout << "Unable to open " << filePath.c_str() << "." << std::endl;
    }

    return shaderCode;
}
