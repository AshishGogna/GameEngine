//
//  Matrix4.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 04/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Matrix4.hpp"

Matrix4::Matrix4()
{
    float m[4][4] = {0};
    SetMat(m);
}

Matrix4::Matrix4(float m[4][4])
{
    SetMat(m);
}

void Matrix4::SetMat(float m[4][4])
{
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            mat[i][j] = m[i][j];
        }
    }
}

Matrix4 Matrix4::Identity()
{
    mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0;   mat[0][3] = 0;
    mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0;   mat[1][3] = 0;
    mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1;   mat[2][3] = 0;
    mat[3][0] = 0; mat[3][1] = 0; mat[3][2] = 0;   mat[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::TranslationMatrix(Vector3 by)
{
    mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0;   mat[0][3] = by.x;
    mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0;   mat[1][3] = by.y;
    mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1;   mat[2][3] = by.z;
    mat[3][0] = 0; mat[3][1] = 0; mat[3][2] = 0;   mat[3][3] = 1;
    
    return *this;
}

Matrix4 Matrix4::operator*(Matrix4 m)
{
    Matrix4 res = Matrix4();
    
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            res.mat[i][j] = mat[i][0] * m.mat[0][j] +
                            mat[i][1] * m.mat[1][j] +
                            mat[i][2] * m.mat[2][j] +
                            mat[i][3] * m.mat[3][j];
        }
    }
    
    return res;
}

string Matrix4::ToString()
{
    string s;
    
    s += to_string(mat[0][0]) + "\t" + to_string(mat[0][1]) + "\t" + to_string(mat[0][2]) + "\t" + to_string(mat[0][3]) +"\n";
    
    s += to_string(mat[1][0]) + "\t" + to_string(mat[1][1]) + "\t" + to_string(mat[1][2]) + "\t" + to_string(mat[1][3]) +"\n";
    
    s += to_string(mat[2][0]) + "\t" + to_string(mat[2][1]) + "\t" + to_string(mat[2][2]) + "\t" + to_string(mat[2][3]) +"\n";
    
    s += to_string(mat[3][0]) + "\t" + to_string(mat[3][1]) + "\t" + to_string(mat[3][2]) + "\t" + to_string(mat[3][3]);
    
    return s;
}
