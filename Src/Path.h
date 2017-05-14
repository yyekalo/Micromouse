//
//  Path.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/6/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Path_hpp
#define Path_hpp


#include "Vector.h"
#include <stack>







class dirVector {
    
public:
    
    dirVector();
    
    dirVector(double mag, Direction dir);
    
    ~dirVector();
    
    double Mag() const;
    
    Direction Dir() const;
    
    bool operator==(dirVector dirvec);
    
    bool operator!=(dirVector dirvec);
    
    void      setMag(double mag);
    
    void      Dir(Direction dir);
    
    Node      getNode(const Node& from);
    
    
    
    
private:
    
    double mag;
    
    Direction dir;
    
};



//ToDo overload < > operators to calcualte which path is the fastest
class Path{
    
public:
    
    Path(Node start = Node(1,1));
    
    ~Path();
    
    dirVector  next();
    
    Node       nextNode();
    
    void add(dirVector toBeAdded);
    
    void add(const Node& to);
    
    bool operator==(Path node);
    
    bool operator!=(Path node);
    
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
