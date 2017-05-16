//
//  Mouse.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Mouse.h"




Mouse::Mouse(){
    
}








Mouse::Mouse(Position currentPosition, Direction currentDirection, Node intCenter){
    
    _position = currentPosition;
    
    _center = intCenter;
    
    _heading = currentDirection;
    
    maze = Maze();
    
    
}








Mouse::~Mouse(){
    
}







Position Mouse::position(){
    
    return _position;
}







Node      Mouse::positionNode(){
    
    return Node(_position.x() / sideWidth , _position.y() / sideWidth);
    
}







void Mouse::setPosition(Node position){
    
    _position = Position(position.x() * sideWidth , position.y() * sideWidth);
    
}







void Mouse::sePosition(Position position){
    
    _position = position;
}







double    Mouse::Heading(){
    
    return _heading;
}







Direction  Mouse::HeadingDir(){
    
    return static_cast<Direction>( _heading / 45);
    
}







void Mouse::setHeading(Direction dir){
    
    _heading = dir * 45;
    
}







void Mouse::setHeading(double dir){
    
    _heading = dir;
    
}







bool Mouse::isWall(IRWall dir){
    
    return true;
}







void faceDir(Direction dir){
    
    
    
}







void Mouse::Move(dirVector dir){
    
}








bool Mouse::exploreMaze(){
    
    Path temp = maze.findPath(positionNode(), _center);
    
    
    while (!temp.empty()) {
        
        
         _followUntillBroken(temp);
        
        temp = maze.findPath(positionNode(), _center);
        
        
        
    }
    
    
    
    return true;
    
    
}








bool Mouse::followPath(Path path){
    
    
    
    
    
    return true;
    
    
}









bool Mouse::gotoNode(Node destination){
    
    
   return  _followUntillBroken(maze.findPath(positionNode(), destination));
    
}








bool Mouse::_followUntillBroken(Path path){
    
    while (!path.empty()) {
        
    
    
//   Node nextPosition = path.peekNode();
//    
//    if (isWall(E)) {
//        
//        maze.removeNeighbour(positionNode(), E);
//    }
//    
//    
//    
//    if (isWall(W)) {
//        
//        maze.removeNeighbour(positionNode(), W);
//        
//    }
//    
//    
//    
//    if(isWall(positionNode().whichSide(nextPosition))){
//        
//        maze.removeNeighbour(positionNode(), nextPosition);
//        
//        return false;
//    }
//    
//    
//    Move(path.next());
//    
//    }
    
    }
    return true;
    
}














