//
//  Util.cpp
//  GameEngine
//
//  Created by Ashish Gogna on 29/12/17.
//  Copyright © 2017 Ashish Gogna. All rights reserved.
//

#include "Util.hpp"

void Util::Exit()
{
    exit(EXIT_FAILURE);
}

void Util::Print(std::string s)
{
    std::cout << s << endl;
}

vector<string> Util::Split(std::string txt, char ch)
{
    vector<std::string> strs;
    unsigned int pos = (int)txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();
    
    // Decompose statement
    while( pos != (int)std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos  ) );
        initialPos = pos + 1;
        
        pos = (int)txt.find( ch, initialPos );
    }
    
    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min<unsigned int>( pos, (int)txt.size() ) - initialPos + 1 ) );
    
    return strs;
}
