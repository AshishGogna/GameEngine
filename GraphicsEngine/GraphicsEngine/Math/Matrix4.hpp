//
//  Matrix4.hpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 04/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#ifndef Matrix4_hpp
#define Matrix4_hpp

#include <stdio.h>
#include <iostream>
#include "Vector3.hpp"

using namespace std;

class Matrix4
{
private:
    void SetMat(float m[4][4]);
    
public:
    float mat[4][4];

    Matrix4();
    Matrix4(float m[4][4]);
    
    Matrix4 Identity();
    Matrix4 TranslationMatrix(Vector3 by);
    Matrix4 RotationMatrix(Vector3 by);
    Matrix4 ScaleMatrix(Vector3 by);

    Matrix4 operator * (Matrix4 m);
    string ToString();
};

#endif /* Matrix4_hpp */
