//
//  Matrix4.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Matrix4.hpp"
#include <math.h>

Matrix4::Matrix4()
{
    float m[4][4] = {0};
    SetMatrix(m);
}

Matrix4::Matrix4(float m[4][4])
{
    SetMatrix(m);
}

void Matrix4::SetMatrix(float m[4][4])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            matrix[i][j] = m[i][j];
        }
    }
}

Matrix4 Matrix4::InitIdentity()
{
    matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;   matrix[0][3] = 0;
    matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;   matrix[1][3] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;   matrix[2][3] = 0;
    matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0;   matrix[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::InitTranslation(float x, float y, float z)
{
    matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;   matrix[0][3] = x;
    matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;   matrix[1][3] = y;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;   matrix[2][3] = z;
    matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0;   matrix[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::InitRotation(float x, float y, float z)
{
    Matrix4 rX = Matrix4();
    Matrix4 rY = Matrix4();
    Matrix4 rZ = Matrix4();
    
    //Degrees to Randians
    x = x * (M_PI/180);
    y = y * (M_PI/180);
    z = z * (M_PI/180);
    
    rZ.matrix[0][0] = cosf(z); rZ.matrix[0][1] = -sinf(z); rZ.matrix[0][2] = 0;         rZ.matrix[0][3] = 0;
    rZ.matrix[1][0] = sinf(z); rZ.matrix[1][1] =  cosf(z); rZ.matrix[1][2] = 0;         rZ.matrix[1][3] = 0;
    rZ.matrix[2][0] = 0;       rZ.matrix[2][1] = 0;        rZ.matrix[2][2] = 1;         rZ.matrix[2][3] = 0;
    rZ.matrix[3][0] = 0;       rZ.matrix[3][1] = 0;        rZ.matrix[3][2] = 0;         rZ.matrix[3][3] = 1;
    
    rX.matrix[0][0] = 1;       rX.matrix[0][1] = 0;        rX.matrix[0][2] = 0;         rX.matrix[0][3] = 0;
    rX.matrix[1][0] = 0;       rX.matrix[1][1] = cosf(x);  rX.matrix[1][2] = -sinf(x);  rX.matrix[1][3] = 0;
    rX.matrix[2][0] = 0;       rX.matrix[2][1] = sinf(x);  rX.matrix[2][2] = cosf(x);   rX.matrix[2][3] = 0;
    rX.matrix[3][0] = 0;       rX.matrix[3][1] = 0;        rX.matrix[3][2] = 0;         rX.matrix[3][3] = 1;

    rY.matrix[0][0] = cosf(y); rY.matrix[0][1] = 0;        rY.matrix[0][2] = -sinf(y);  rY.matrix[0][3] = 0;
    rY.matrix[1][0] = 0;       rY.matrix[1][1] = 1;        rY.matrix[1][2] = 0;         rY.matrix[1][3] = 0;
    rY.matrix[2][0] = sinf(y); rY.matrix[2][1] = 0;        rY.matrix[2][2] = cosf(y);   rY.matrix[2][3] = 0;
    rY.matrix[3][0] = 0;       rY.matrix[3][1] = 0;        rY.matrix[3][2] = 0;         rY.matrix[3][3] = 1;
    
    SetMatrix(rZ.Multiply(rY.Multiply(rX)).matrix);

    return *this;
}

Matrix4 Matrix4::InitScale(float x, float y, float z)
{
    matrix[0][0] = x; matrix[0][1] = 0; matrix[0][2] = 0;   matrix[0][3] = 0;
    matrix[1][0] = 0; matrix[1][1] = y; matrix[1][2] = 0;   matrix[1][3] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = z;   matrix[2][3] = 0;
    matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0;   matrix[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::InitProjection(float fov, float width, float height, float zNear, float zFar)
{
    float ar = width / height;
    float tanHalfFOV = tanf((fov/2) * (M_PI/180));
    float zRange = zNear - zFar;
    
    matrix[0][0] = 1/(tanHalfFOV*ar);  matrix[0][1] = 0;             matrix[0][2] = 0;                     matrix[0][3] = 0;
    matrix[1][0] = 0;                  matrix[1][1] = 1/tanHalfFOV;  matrix[1][2] = 0;                     matrix[1][3] = 0;
    matrix[2][0] = 0;                  matrix[2][1] = 0;             matrix[2][2] = (-zNear-zFar)/zRange;  matrix[2][3] = 2*zFar*zNear/zRange;
    matrix[3][0] = 0;                  matrix[3][1] = 0;             matrix[3][2] = 1;                     matrix[3][3] = 0;
    
    return *this;
}

Matrix4 Matrix4::Multiply(Matrix4 m)
{
    Matrix4 res = Matrix4();
    
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            res.matrix[i][j] = matrix[i][0] * m.matrix[0][j] +
                               matrix[i][1] * m.matrix[1][j] +
                               matrix[i][2] * m.matrix[2][j] +
                               matrix[i][3] * m.matrix[3][j];
        }
    }
    
    return res;
}

string Matrix4::ToString()
{
    string s;
    
    s += to_string(matrix[0][0]) + "\t" + to_string(matrix[0][1]) + "\t" + to_string(matrix[0][2]) + "\t" + to_string(matrix[0][3]) +"\n";

    s += to_string(matrix[1][0]) + "\t" + to_string(matrix[1][1]) + "\t" + to_string(matrix[1][2]) + "\t" + to_string(matrix[1][3]) +"\n";

    s += to_string(matrix[2][0]) + "\t" + to_string(matrix[2][1]) + "\t" + to_string(matrix[2][2]) + "\t" + to_string(matrix[2][3]) +"\n";

    s += to_string(matrix[3][0]) + "\t" + to_string(matrix[3][1]) + "\t" + to_string(matrix[3][2]) + "\t" + to_string(matrix[3][3]);

    return s;
}
