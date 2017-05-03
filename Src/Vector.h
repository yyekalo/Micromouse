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




enum Direction {
    
    N=0,E=2,S=3,W=4,
    
    NW,NE,SE,SW,
    
};


template<class T>
class Location{
    
public:
    
    Location();
    
    Location(T _x,T _y);

    
  //  Location(const Location<T>  & location);
    
    //getters
    T x() const;
    T y() const;
    
    std::string returnString();
    
    
    //seter
    void x(T X);
    
    void y(T Y);
    
    
    Location operator+(Location location);
    
    Location operator-(Location location);
    
    Location operator*(T scale);
    
   // bool    operator=(const Location& loc);
    
    bool    operator==(Location location);
    
    bool    operator!=(Location location);
    
    bool    operator<(const Location& location);
    
    bool    operator>(const Location& location);
    
    bool    operator==(const Location& loc2) const;
    
    
private:
    
    T _x,_y;
};

//Location(position)  of a cell(node)
typedef Location<int> Node;
//abslute coordinate of the mouse in the maze
typedef Location<float> position;





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
bool     Location<T>::operator<(const Location& location){
    
    return this->_x < location.x() & this-> _y < location.y();
}







template<class T>
bool     Location<T>::operator>(const Location& location){
    
    return this->_x > location.x() & this-> _y > location.y();
}






template<class T>
bool  Location<T>::operator==(const Location& loc2) const{
    
    return (loc2.x() == this->_x && this->_y == loc2.y());
    
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
