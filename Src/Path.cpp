//
//  Path.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/6/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Path.h"


dirVector::dirVector(){
    
    
}
















dirVector::dirVector(double mag, Direction  dir){
    
    this -> mag = mag;
    
    this -> dir = dir;
    
}
    










dirVector::~dirVector(){
    
}








float dirVector::Mag() const{
    
    return mag;
    
}








Direction dirVector::Dir() const{
    
    return dir;
    
}










void      dirVector::Mag(float mag){
    
    this -> mag = mag;
    
}









void      dirVector::Dir(Direction dir){
    
    this -> dir =  dir;
    
    
}








Node      dirVector::getNode(const Node& form){
    
    int distance =  int(this -> mag);
    
    int diagonal = int(sqrt(round(pow(mag,2)) /2));
    
    
    switch (dir) {
            
        case N:
            
            return Node(form.x(),form.y() - distance);

            
            break;
            
        case NE:
            
            
            return Node(form.x() -diagonal,form.y() -diagonal);

            
            break;
            
        case E:
            
            return Node(form.x() -distance,form.y());
            
            break;
            
        case SE:
            
            
            return Node(form.x()-diagonal,form.y() + diagonal);
            
            break;
            
        case S:
            
            return Node(form.x(),form.y() + distance);
            
            break;
            
        case SW:
            
            return Node(form.x() + diagonal,form.y() + diagonal );
            
            break;
            
        case W:
            
            return Node(form.x() + distance,form.y());
            
            break;
            
        case NW:
            
            return Node(form.x() + diagonal,form.y() -diagonal);
            
            break;
    }
    
    
    
}







/*******************************************************************************************************************************************
 
 Start of definition of Path class
 
 ******************************************************************************************************************************************/






Path::Path(Node start){
    
    this -> lastNode = start;
    
}








Path::~Path(){
    
}








dirVector  Path::next(){
    
    dirVector temp = path.top();
    
    path.pop();
    
    return temp;
    
}







void Path::add(dirVector toBeAdded){
    
    path.push(toBeAdded);
    
    lastNode = toBeAdded.getNode(lastNode);
    
}









Node       Path::nextNode(){
    
    Node temp = path.top().getNode(lastNode);
   
    path.pop();
    
    lastNode = temp;
    
    return temp;
    
}








void Path::add(const Node& to){
    
    
    add(dirVector(lastNode.distance(to), lastNode.whichSide(to)));
    
    lastNode = to;
}








dirVector  Path::peek(){
    
    return path.top();
    
}










bool Path::empty(){
    
    return path.empty();
}









int Path::size(){
    
    return path.size();
    
}








Node Path::start(){
    
    return lastNode;
}








