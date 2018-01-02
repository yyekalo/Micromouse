//
//  Mouse.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//
#pragma once
#ifndef Mouse_hpp
#define Mouse_hpp

#include <stdio.h>



//My classes
#include "Vector.h"
#include "Path.h"
#include "Maze.h"
#include "VirtualMaze.h"
#include "IRSensors.h"


#define sideWidth 18


//TODO: improve the setter and getter of posistion all four function.

class Mouse{
    
    
    
    
public:
    
    
    Mouse(Position currentPosition=Position(0,0), Direction currentDirection = N,Node center=Node(8,8));
    
    ~Mouse();
    
    
    //seter and getter for private members
    
    Position position();
    
    Node      positionNode();
    
    void setPosition(Node position);
    
    void sePosition(Position position);
    
    double    Heading();
    
    Direction  HeadingDir();
    
    void setHeading(Direction dir);
    
    void setHeading(double dir);
    
    
    
    
    //bool isWall(IRWall dir);  //to be implmented after IR-class is build
    
    bool isWall(Direction dir);
    
    void faceDir(Direction dir);
    
    void Move(dirVector dir);
    
    bool exploreMaze();
    
    bool followPath(Path path);
    
    bool gotoNode(Node destination);
    
    void draw();
    
    bool isExplored(Path path);
    
    //returns the first explored node in the path
    Node getExplored(Path path);
    
   
    
    
    
//private:
    
    bool _followUntillBroken(Path path);
    
    Position _position;
    
    Node _center;
    
    Node _start;
    
    double _heading;
    
    Maze maze;
    
    bool mazeFullyExplored;
    
    VirtualMaze virmaze;
    
    Path bestPath;
    
};

#endif /* Mouse_hpp */
