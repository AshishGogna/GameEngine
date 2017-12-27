//
//  Matrix4.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 27/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Matrix4.hpp"

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
