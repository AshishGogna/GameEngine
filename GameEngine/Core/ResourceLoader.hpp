//
//  ResourceLoader.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 01/01/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef ResourceLoader_hpp
#define ResourceLoader_hpp

#include <stdio.h>
#include <iostream>
#include<fstream>
#include "Mesh.hpp"
#include <vector>
#include "Texture.hpp"

class ResourceLoader
{
public:
    static std::string LoadShader(std::string filePath);
    static Mesh LoadMesh(std::string filePath);
    static Texture LoadTexture(std::string filePath);
    static vector<string> Split(std::string txt, char ch);
};

#endif /* ResourceLoader_hpp */
