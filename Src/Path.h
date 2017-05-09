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
#include <assert.h>


class dirVector {
    
public:
    
    dirVector();
    
    dirVector(double mag, Direction dir);
    
    ~dirVector();
    
    float Mag() const;
    
    Direction Dir() const;
    
    void      Mag(float mag);
    
    void      Dir(Direction dir);
    
    Node      getNode(const Node& from);
    
    
    
    
private:
    
    double mag;
    
    Direction dir;
    
};




class Path{
    
public:
    
    Path(Node start = Node(1,1));
    
    ~Path();
    
    dirVector  next();
    
    Node       nextNode();
    
    void add(dirVector toBeAdded);
    
    void add(const Node& to);
    
    bool empty();
    
    int size();
    
    dirVector  peek();
    
    Node  peekNode();
    
    Node start();
    
    void print();

    
private:
    
    Node lastNode;
    
    std::stack<dirVector>  path;
    
    
    
};
#endif /* Path_hpp */
