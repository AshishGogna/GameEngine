//
//  Matrix4.hpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#ifndef Matrix4_hpp
#define Matrix4_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Matrix4
{
private:
    void SetMatrix(float m[4][4]);
    
public:
    float matrix[4][4];

    Matrix4();
    Matrix4(float m[4][4]);
    Matrix4 InitIdentity();
    Matrix4 InitTranslation(float x, float y, float z);
    Matrix4 InitRotation(float x, float y, float z);
    
    Matrix4 Multiply(Matrix4 m);
    
    string ToString();
};

#endif /* Matrix4_hpp */
