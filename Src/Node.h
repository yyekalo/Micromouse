//
//  Node.hpp
//  lkn
//
//  Created by Yikealo Abraha  on 4/19/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "Vector.h"
#include "Vector"

class Node {
    
    
public:
    template <class T>
    Node(Location<T> location);
    ~Node();
    Location<int> getLocation();
    Node* getparent();
    void setparent(Node* const parent);
    bool wall[3];
    
    
private:
    
    Location<int> location;
    
    std::vector<Location<int>> neighbors;
    
    Node* parent;
    
    
    
    
    
    
    
    
    
    
};

#endif /* Node_hpp */
