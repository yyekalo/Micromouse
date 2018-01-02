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
            
            return Node(form.x(),form.y() + distance);

            
            break;
            
        case NE:
            
            
            return Node(form.x() +diagonal,form.y() + diagonal);

            
            break;
            
        case E:
            
            return Node(form.x() +distance,form.y());
            
            break;
            
        case SE:
            
            
            return Node(form.x()+diagonal,form.y() - diagonal);
            
            break;
            
        case S:
            
            return Node(form.x(),form.y() - distance);
            
            break;
            
        case SW:
            
            return Node(form.x() - diagonal,form.y() - diagonal );
            
            break;
            
        case W:
            
            return Node(form.x() - distance,form.y());
            
            break;
            
        case NW:
            
            return Node(form.x() - diagonal,form.y() + diagonal);
            
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
    
    Direction kk = static_cast<Direction>(toBeAdded.Dir()+7);
    
    toBeAdded.Dir(kk);
    
    lastNode = toBeAdded.getNode(lastNode);
    
}











void Path::add(const Node& to){
    
    add(dirVector(to.distance(lastNode),to.whichSide(lastNode)));
    
    lastNode = to;
}







Node       Path::nextNode(){
    
    //assert(empty());
    
    
    Node temp = path.top().getNode(lastNode);
   
    path.pop();
    
    lastNode = temp;
    
    return temp;
    
}









bool Path::operator==(Path node){
    
    if (node.size()!=(path.size())) {
        
        return false;
        
    }
    
    std::stack<dirVector>  temp1 = path;
    
    std::stack<dirVector>  temp2 = node.path;
    
    while (!temp1.empty() || !temp2.empty()) {
        
        if (temp2.top() != temp1.top()) {
            
            return false;
        }
        
        temp1.pop();
        
        temp2.pop();
        
    }
   
    
    return true;
    
}








bool Path::operator!=(Path node){
    
    return !(this->operator==(node));
    
}








bool Path::operator<(Path second){
    
    
    std::stack<dirVector> temp = path;
    
    int totalpathLength = 0;
    
    while (!temp.empty()) {
        
        totalpathLength += temp.top().Mag();
        
    }
    
    while (path.empty()) {
        
        
    }
    
    return true;

}







bool Path::operator>(Path path){
    
    return true;
    
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








//TODO:-> fix this function need some cleaning to do.
void Path::print(){
    
    std::stack<dirVector>  tempPath = path;
    
    Node tempNode =  lastNode;
    
    std::cout << tempNode.returnString()<<" ";
    
    while (!tempPath.empty()) {
        
        
        
        tempNode = tempPath.top().getNode(tempNode);
        
        tempPath.pop();
        
        

        
        std::cout << tempNode.returnString()<<" ";
        
        
    }
    
    std::cout << std::endl;

    

    
    
}





//TODO: important this function needs a code review
//Doing this so i can move onthe simulation
//REVIEW this function!!
Path Path::compress(){
    
   Path temp = * this ;

    Path toReturn(temp.lastNode);

//    dirVector currentDirVector, lastDirvector = temp.next();
//
//    bool write = false;
//
//
//    while (!temp.empty()) {
//
//        currentDirVector = temp.next();
//
//        if (currentDirVector.Dir() == lastDirvector.Dir()) {
//
//            lastDirvector.Mag(lastDirvector.Mag()+currentDirVector.Mag());
//
//            write = true;
//
//        } else {
//
//            toReturn.add(lastDirvector);
//
//            lastDirvector = currentDirVector;
//
//            write =  false;
//
//        }
//
//    }
//    if (write) {
//
//
//    toReturn.add(lastDirvector);
//    }
//
//    toReturn.lastNode = temp.lastNode;
//
//
//    return toReturn;
    
    Node current, last = temp.nextNode();

    while (!temp.empty()) {
        
        current = temp.nextNode();
        
        if (toReturn.lastNode.whichSide(current) != toReturn.lastNode.whichSide(last) ) {
            
            toReturn.add(last);
            
            
        }
        
        last = current;
        
        
    }
    
    toReturn.add(last);
    
    Path tobe(toReturn.lastNode);
    
    while (!toReturn.empty()) {
        
        tobe.add(toReturn.nextNode());
    }
    
    return tobe;
    
}









float Path::cost(){
    
//    Path temp = compress();
//
//     Node temp2 = temp.peekNode();
//
//    dirVector current, last = temp.next();
//
//    temp2 = temp.peekNode();
//
//   float moveCost1,moveCost2, cost = 0.19*pow(last.Mag(), 0.5);
//
//
//    while (!temp.empty()) {
//
//        temp2 = temp.peekNode();
//
//        current = temp.next();
//
//        moveCost1 = 0.19*pow(current.Mag(), 0.5);
//
//        cost += moveCost1; //0.19*pow(current.Mag(), 0.5);
//
//      moveCost2 = abs( static_cast<int>(current.Dir()) - static_cast<int>(last.Dir())) < 4 ?
//
//        abs( static_cast<int>(current.Dir()) - static_cast<int>(last.Dir())) * Turn45 : 8-abs( static_cast<int>(current.Dir()) - static_cast<int>(last.Dir())) * Turn45;
//
//        cost += moveCost2;
//    }
//
//
//    return cost;
//
    Path compressedPath = compress();
    
    Direction lastDirection;
    
    float cost = 0;
    
    
    while (compressedPath.size()>1){

        cost +=  0.19*pow(compressedPath.peek().Mag(), 0.5);
        
        lastDirection = compressedPath.next().Dir();
        
        cost += (lastDirection - compressedPath.peek().Dir())*Turn45;
        
    }
    
    cost +=  0.19*pow(compressedPath.peek().Mag(), 0.5);
    
    return cost;
    
}



