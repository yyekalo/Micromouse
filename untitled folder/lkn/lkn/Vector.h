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

template<class T>
class Location{
    
public:
    
    Location(T _x,T _y);
    
   // Location(const Location& location);
    
    //getters
    T x();
    T y();
    
    //seter
    void x(T X);
    void y(T Y);
    
    
    Location operator+(Location location);
    Location operator-(Location location);
    Location operator*(T scale);
    bool     operator==(Location location);
    bool     operator!=(Location location);
    
    
private:
    
    T _x,_y;
};




template<class T>
Location<T>::Location(T X,T Y){
    
    x(X);
    y(Y);
    
}





//TODO: implment construction by reference
//template<class T>
//Location<T>::Location(const Location& location){
//    
//    x(location.x());
//    y(location.y());
//    
//}





template<class T>
T Location<T>::x(){
    
    return this ->_x;
    
}






template<class T>
T Location<T>::y(){
    
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

#endif /* Vector_hpp */
