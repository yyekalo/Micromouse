//
//  Node.cpp
//  lkn
//
//  Created by Yikealo Abraha  on 4/19/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Node.h"


template <class T>
Node::Node(Location<T> location){
    
    this-> location = location;
    
}






Node::~Node(){
    
    
}






Location<int> Node::getLocation(){
    
    return this -> location;
    
}






Node* Node::getparent(){
    
    return this -> parent;
    
}






void Node::setparent(Node* const parent){
    
    this -> parent = parent;
    
}
