//
//  main.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 26/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Window.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix4.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    Vector2 v = Vector2(10, 12);
    cout << v.ToString() << endl;
    
    Vector3 v3 = Vector3(10, 12, 24);
    cout << v3.ToString() << endl;
    
    Matrix4 m = Matrix4().InitIdentity();
    cout << m.ToString() << endl;
    
    Window window = Window();
    while (!window.isCloseRequested())
    {
        window.Update();
    }
    window.Terminate();
    
    return 0;
}
