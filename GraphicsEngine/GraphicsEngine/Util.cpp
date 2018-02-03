//
//  Util.cpp
//  GraphicsEngine
//
//  Created by Ashish Gogna on 03/02/18.
//  Copyright © 2018 Ashish Gogna. All rights reserved.
//

#include "Util.hpp"

void Util::Print(string s)
{
    cout << s << endl;
}

void Util::ExitWithError(string s)
{
    Print(s);
    exit(EXIT_FAILURE);
}
