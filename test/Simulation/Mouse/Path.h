//
//  Path.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/6/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//
#pragma once
#ifndef Path_hpp
#define Path_hpp

#include <stdio.h>
#include "Vector.h"
#include <stack>
#include <assert.h>


//The cost of of movment
#define Turn45   0.785398
//straight movment cost  = 0.19*pow(#cellstoTraverce, 0.5);






class dirVector {
    
public:
    
    dirVector();
    
    dirVector(double mag, Direction dir);
    
    ~dirVector();
    
    float Mag() const;
    
    Direction Dir() const;
    
    bool operator==(dirVector dirvec);
    
    bool operator!=(dirVector dirvec);
    
    void      Mag(float mag);
    
    void      Dir(Direction dir);
    
    Node      getNode(const Node& from);
    
    
    
    
private:
    
    double mag;
    
    Direction dir;
    
};



/*/ToDo overload < > operators to calcualte which path is the fastest
//To be implmented when i collect data on the movement cost when the micromouse is built
 */
class Path{
    
public:
    
    Path(Node start = Node(1,1));
    
    ~Path();
    
    dirVector  next();
    
    Node       nextNode();
    
    bool operator==(Path path);
    
    bool operator!=(Path path);
    
    bool operator<(Path path);
    
    bool operator>(Path path);
    
    void add(dirVector toBeAdded);
    
    void add(const Node& to);
    
    bool empty();
    
    int size();
    
    dirVector  peek();
    
    Node  peekNode();
    
    Node start();
    
    void print();
    
    Path compress();
    
    float cost();

    
private:
    
    Node lastNode;
    
    std::stack<dirVector>  path;
    
    
    
};
#endif /* Path_hpp */
