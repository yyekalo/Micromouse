////
////  Mouse.cpp
////  teensyMicromouse
////
////  Created by Yikealo Abraha  on 5/13/17.
////  Copyright © 2017 Yikealo Abraha . All rights reserved.
////
//
//#include "Mouse.h"
//
//
//
//
//Mouse::Mouse(){
//    
//}
//
//
//
//
//
//
//
//
//Mouse::Mouse(Position currentPosition, Direction currentDirection, Node intCenter){
//    
//    position = currentPosition;
//    
//    center = intCenter;
//    
//    heading = currentDirection;
//    
//    maze = Maze();
//    
//    
//}
//
//
//
//
//
//
//
//
//Mouse::~Mouse(){
//    
//}
//
//
//
//
//
//
//
//Node Mouse::getPosition(){
//    
//    return Node(ceil(position.x()/cellSide),ceil(position.y()/cellSide));
//    
//}
//
//
//
//
//
//
//
//
//
//
//Position Mouse::getFloatPosition(){
//    
//    return position;
//    
//    
//}
//
//
//
//
//
//
//
//
//void Mouse::setPosition(Node newPosition){
//    
//    position = position;
//}
//
//
//
//
//
//
//
//
//
//
//void Mouse::setPosition(Position newPosition){
//    
//    position = newPosition;
//}
//
//
//
//
//
//
//
//
//
//Direction Mouse::getHeading(){
//    
//    return static_cast<Direction>( heading / 45);;
//    
//}
//
//
//
//
//
//
//
//
//
//
//float Mouse::getFloatHeading(){
//    
//    return heading;
//}
//
//
//
//
//
//
//
//
//void Mouse::setHeading(Direction newHeading){
//    
//    heading = float(newHeading * 45);
//    
//}
//
//
//
//
//
//
//
//
//
//
//void Mouse::setHeading(float newHeading){
//    
//    heading = newHeading;
//    
//}
//
//
//
//
//
//
//
//
//
//
//bool Mouse::isWall(Direction dir){
//    
//    
//    
//    
//    return true;
//}
//
//
//
//
//
//
//
//
//
//
//void Mouse::faceDir(Direction dir){
//    
//    std::cout << "SSDF"<<std::endl;
//    
//}
//
//
//
//
//
//
//
//void Mouse::Move(dirVector dir){
//    
//     std::cout << "SSDF"<<std::endl;
//    
//}
//
//
//
//
//
//
//
//
//bool Mouse::exploreMaze(){
//    
//    Path temp = maze.findPath(getPosition(), center);
//    
//    
//    while (!temp.empty()) {
//        
//        
//         followUntillBroken(temp);
//        
//        temp = maze.findPath(getPosition(), center);
//        
//        
//        
//    }
//
//    return (getPosition() == center);
//    
//}
//
//
//
//
//
//
//
//
//bool Mouse::followPath(Path path){
//    
//    
//    
//    while (!path.empty()) {
//        
//        Move(path.next());
//        
//        
//    }
//    
//    
//    //TODO: make return true if tranversed the whole path
//    return true;
//    
//    
//}
//
//
//
//
//
//
//
//
//
//bool Mouse::followUntillBroken(Path path){
//    
//   Node nextPosition;
//    
//    while (path.empty()) {
//        
//      nextPosition = path.nextNode();
//    
//    if (isWall(E)) {
//        
//        maze.removeNeighbour(getPosition(), E);
//    }
//    
//    
//    
//    if (isWall(W)) {
//        
//        maze.removeNeighbour(getPosition(), W);
//        
//    }
//    
//    
//    
//    if(isWall(getPosition().whichSide(nextPosition))){
//        
//        maze.removeNeighbour(getPosition(), nextPosition);
//        
//        return false;
//    }
//    
//    
//    Move(dirVector(getPosition().distance(nextPosition), getPosition().whichSide(nextPosition)));
//        
//      
//    
//    }
//    
//    return true;
//    
//    
//}
//
//
//
//
//
