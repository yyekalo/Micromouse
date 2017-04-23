//
//  Node.cpp
//  lkn
//
//  Created by Yikealo Abraha  on 4/19/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Node.h"








template <class T>
Node::Node(Location<int> location){
    
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










bool Node::isWall(Direction heading){
    
    return wall[(int)heading];
}






void Node::setWall(Direction heading){
    
    wall[(int)heading] = true;
    
}





void Node::resetWall(Direction heading){
    
    wall[(int)heading] = false;
    
}







int Node::getC(){
    
    return cost_so_far;
}






int Node::getH(){
    
    return hurestic;
}






bool Node::isExplored(){
    
    return explored;
    
}







void Node::setExplored(){
    
    explored =  true;
    
}


