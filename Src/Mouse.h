////
////  Mouse.hpp
////  teensyMicromouse
////
////  Created by Yikealo Abraha  on 5/13/17.
////  Copyright © 2017 Yikealo Abraha . All rights reserved.
////
//
//#ifndef Mouse_hpp
//#define Mouse_hpp
//
//#include <stdio.h>
//
//
//
////My classes
//#include "Vector.h"
//#include "Path.h"
//#include "Maze.h"
//
//
//#define cellSide 18
//
//
//
//
//
//
//class Mouse{
//    
//    
//    
//    Mouse();
//    
//    Mouse(Position currentPosition=Position(0,0), Direction currentDirection = N,Node center=Node(8,8));
//    
//    ~Mouse();
//    
//    Node getPosition();
//    
//    Position getFloatPosition();
//    
//    void  setPosition(Node newPosition);
//    
//    void  setPosition(Position newPosition);
//    
//    Direction getHeading();
//    
//    float getFloatHeading();
//    
//    void setHeading(Direction newHeading);
//    
//    void setHeading(float newHeading);
//    
//    bool isWall(Direction dir);
//    
//    void faceDir(Direction dir);
//    
//    void Move(dirVector dir);
//    
//    bool exploreMaze();
//    
//    bool followPath(Path path);
//    
//    
//    
//   
//    
//    
//    
//private:
//    
//    
//    
//    bool followUntillBroken(Path path);
//    
//    Position position;
//    
//    Node center;
//    
//    float heading;
//    
//    Maze maze;
//    
//    
//};
//
//#endif /* Mouse_hpp */
