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
    









dirVector::dirVector(Node from, Node to){
    
    this->dir = from.whichSide(to);
    
    this->mag = sqrt(pow(from.x()-to.x(),2)+ pow(from.y()-to.y(),2));
    
}









dirVector::~dirVector(){
    
}








float dirVector::Mag() const{
    
    return mag;
    
}








Direction dirVector::Dir() const{
    
    return dir;
    
}










bool dirVector::operator==(dirVector dirvec){
    
    return mag == dirvec.mag && dir == dirvec.dir;
    
}









bool dirVector::operator!=(dirVector dirvec){
    
    return mag != dirvec.mag || dir != dirvec.dir;

    
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
    
    //assert(empty());
    
    
    Node temp = path.top().getNode(lastNode);
   
    path.pop();
    
    lastNode = temp;
    
    return temp;
    
}









bool Path::operator==(Path node){
    
    if (node.size()!=path.size()) {
        
        return false;
        
    }
    
    std::stack<dirVector>  temp1 = path;
    
    std::stack<dirVector>  temp2 = node.path;
    
    while (temp1.empty() || temp2.empty()) {
        
        if (temp2.top() != temp1.top()) {
            
            return false;
        }
        
        temp1.pop();
        
        temp2.pop();
        
    }
   
    
    return true;
    
}








bool Path::operator!=(Path node){
    
    if (node.size()!=path.size()) {
        
        return true;
        
    }
    
    std::stack<dirVector>  temp1 = path;
    
    std::stack<dirVector>  temp2 = node.path;
    
    //TODO
    
//    while (temp1.empty() || temp2.empty()) {
//        
//        if (temp2.top() == temp1.top()) {
//            
//            return true;
//        }
//        
//        temp1.pop();
//        
//        temp2.pop();
//        
//    }
//    
    
    return false;
    
}











void Path::add(const Node& to){
    
    
    add(dirVector(lastNode.distance(to), lastNode.whichSide(to)));
    
    lastNode = to;
}








dirVector  Path::peek(){
    
    return path.top();
    
}









Node  Path::peekNode(){
    
    
    return peek().getNode(start());
    
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









void Path::print(){
    
    std::stack<dirVector>  tempPath = path;
    
    Node tempNode =  lastNode;
    
    
    std::cout << lastNode.returnString() << " -> " ;
    
    while (!tempPath.empty()) {
        
        
        
        tempNode = tempPath.top().getNode(tempNode);
        
        tempPath.pop();
        
        

        
        std::cout << tempNode.returnString() <<  " -> " ;
        
        
    }
    
    std::cout << std::endl;

    
}






