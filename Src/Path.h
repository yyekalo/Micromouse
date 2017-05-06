//
//  Path.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/6/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Path_hpp
#define Path_hpp

#include <stdio.h>
#include "Vector.h"
#include <stack>

union Magnitude {
    
    float f;
    
    int i;
};






class dirVector {
    
public:
    
    dirVector();
    
    //dirVector();
    
    ~dirVector();
    
    Magnitude getMag();
    
    Direction getDir();
    
    
private:
    
    Magnitude mag;
    
    Direction dir;
    
};




class Path{
    
public:
    
    Path();
    
    ~Path();
    
    dirVector  next();
    
    void add(dirVector toBeAdded);
    
    dirVector  peek();

    
private:
    
    std::stack<dirVector>  path;
    
    
    
};
#endif /* Path_hpp */
