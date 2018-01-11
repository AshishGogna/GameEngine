//
//  RenderUtil.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef RenderUtil_hpp
#define RenderUtil_hpp

#include <stdio.h>
#include <iostream>
#include "Vector3.hpp"

#endif /* RenderUtil_hpp */

class RenderUtil
{
public:
    static void ClearScreen();
    static void InitGraphics();
    static std::string GetOpenGLVersion();
    static void SetTextures(bool enabled);
    static void SetClearColor(Vector3 col);
};
