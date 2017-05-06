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








//void dirVector::dirVector(const Node& from, const Node& to) {
//                         
//    mag = sqrt(pow(abs(from.x()-to.x()),2) + pow(abs(from.y()-to.y()),2));
//    
//}

    










dirVector::~dirVector(){
    
}








Magnitude dirVector::getMag(){
    
    return mag;
    
}








Direction dirVector::getDir(){
    
    return dir;
    
}








Path::Path(){
    
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
    
}










dirVector  Path::peek(){
    
    return path.top();
    
}








