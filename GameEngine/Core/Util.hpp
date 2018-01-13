//
//  Util.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Util_hpp
#define Util_hpp

#include <stdio.h>
#include "Vertex.hpp"
#include <vector>
#include <iostream>
#include "Matrix4.hpp"
#include <GL/glew.h>

class Util
{
public:
    static void Exit();
    static void Print(std::string s);
    static vector<string> Split(std::string txt, char ch);
};

#endif /* Util_hpp */
