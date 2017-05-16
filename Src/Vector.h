//
//  Vector.hpp
//  lkn
//
//  Created by Yikealo Abraha  on 4/18/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <functional>
#include <string>
#include <stack>
#include <iostream>
#include <math.h>



//Directions
enum Direction {
    
   NW=7,  N=0,  NE=1,
    
   W=6,         E=2,
    
   SW=5,  S=4,  SE=3
    
   
    
};

//Direction& operator++(Direction& orig){
//
//
//   // orig =  ( static_cast<int>(orig) == static_cast<int>(NW))? N: static_cast<Direction>(orig+1);
////
////    if (orig==N) {
////
////    }
//
//
//    return orig;
//
//}




template<class T>
class Location{
    
public:
    
    Location();
    
    Location(T _x,T _y);

    
  //  Location(const Location<T>  & location);
    
    //getters
    T x() const;
    T y() const;
    
    std::string returnString() const;
    
    std::string returnString();
    
    
    //seter
    void x(T X);
    
    void y(T Y);
    
    Direction whichSide(const Location<T>& loc) const;
    
    float    distance(const Location<T>& to) const;
        
        
    
    
    Location operator+(Location location);
    
    Location operator-(Location location);
    
    Location operator*(T scale);
    
   // bool    operator=(const Location& loc);
    
    bool    operator==(Location location);
    
    bool    operator!=(Location location);
    
    bool    operator!=(const Location& loc2) const;
    
    bool    operator<(const Location& location) const;
    
    bool    operator>(const Location& location) const;
    
    bool    operator==(const Location& loc2) const;
    
    
private:
    
    T _x,_y;
};

//Location(position)  of a cell(node)
typedef Location<int> Node;
//abslute coordinate of the mouse in the maze
typedef Location<float> Position;




//TODO: get this linker error working

//
//
//
//
//
//
//
//
//
//Direction operator++(Direction& orig , int){
//    
//    Direction temp = orig;
//    
//    ++orig;
//    
//    return temp;
//    
//}







template<class T>
Location<T>::Location(){
    
}













template<class T>
Location<T>::Location(T X,T Y){
    
    x(X);
    y(Y);
}





////TODO: implment construction by reference
//template<class T>
//Location<T>::Location(const Location<T>  & location): _x(location.x(),_y(location.y()){
//    
//    x(location.x());
//    y(location.y());
//    
//    
//}





template<class T>
T Location<T>::x() const{
    
    return this ->_x;
    
}






template<class T>
T Location<T>::y() const{
    
    return this -> _y;
    
}







template<class T>
void Location<T>::x(T X){
    
    this -> _x = X;
    
}





template<class T>
void Location<T>::y(T Y){
    
    this -> _y = Y;
}








//template<class T>
//bool Location<T>::operator=(const Location& loc){
//    
//    return (this->_x == loc.x() && this-> _y == loc.y());
//}



template<class T>
Direction Location<T>::whichSide(const Location<T>& loc) const{
    
    int deltax = loc.x() - _x;
    
    int deltay = loc.y() - _y;
    
    
    
    if (deltax ==0 && deltay > 0 ) {
        
        return N;
        
    }
    else if(deltax == 0 && deltay < 0){
        
        return S;
        
    }
    else if(deltax > 0 && deltay == 0){
        
        return E;
        
    }
    else if(deltax < 0 && deltay == 0){
        
        return W;
        
    } else if (abs(deltay) == abs(deltax)){
        
        if (deltax > 0 && deltay > 0 ) {
            
            return NE;
            
        }
        else if(deltax > 0 && deltay < 0){
            
            return SE;
            
        }
        else if(deltax < 0 && deltay < 0){
            
            return SW;
            
        }
        else if(deltax < 0 && deltay > 0){
            
            return NW;
            
        }
    }
    
    //TODO: hundle this error
    return NW;
    
}









template<class T>
float    Location<T>::distance(const Location<T>& to) const{
    
    return float(sqrt(pow(abs(_x-to.x()),2) + pow(abs(_y-to.y()),2)));

}









template<class T>
Location<T> Location<T>::operator+(Location location){
    
    return Location((x()+location.x()) , (y()+location.y()));
    
}







template<class T>
Location<T> Location<T>::operator-(Location location){
    
    return Location((x()-location.x()) , (y()-location.y()));
    
    
}






template<class T>
Location<T> Location<T>::operator*(T scale){
    
    return Location(scale * (this->_x),scale * (this-> _y));
}






template<class T>
bool    Location<T>::operator==(Location location){
    
    return (this->_x == location.x() && this->_y == location.y());
    
}






template<class T>
bool    Location<T>::operator!=(Location location){
    
    return (this->_x != location.x() | this->_y != location.y());
    
}








template<class T>
bool    Location<T>::operator!=(const Location& loc2) const{
    
    return (this->_x != loc2.x() | this->_y != loc2.y());
    
}








template<class T>
bool     Location<T>::operator<(const Location& location) const{
    
    return this->_x < location.x() & this-> _y < location.y();
}







template<class T>
bool     Location<T>::operator>(const Location& location) const{
    
    return this->_x > location.x() & this-> _y > location.y();
}






template<class T>
bool  Location<T>::operator==(const Location& loc2) const{
    
    return (loc2.x() == this->_x && this->_y == loc2.y());
    
}







template<class T>
std::string Location<T>::returnString() const{
    
    return "<" + std::to_string(_x) + ":" + std::to_string(_y) +">";
    
}








template<class T>
std::string Location<T>::returnString(){
    
    return "<" + std::to_string(_x) + ":" + std::to_string(_y) +">";
    
}

//template<class T>
//std::ostream& operator<<(std::ostream& os, const Location<T>& me ){
//
//    os << "<" << to_string(me.x()) << ":" << to_string(me.y()) << ">";
//
//    return os;
//
//}




//TODO: modify this in the fucure
struct NodeHasher
{
    std::size_t operator()(const Node& k) const
    {
       
        
        return (((std::hash<int>()(k.x()) * 16 )+  std::hash<int>()(k.y())));
        
        
        
    }
};
#endif /* Vector_hpp */
