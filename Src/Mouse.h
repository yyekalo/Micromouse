//
//  Mouse.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Mouse_hpp
#define Mouse_hpp

#include <stdio.h>



//My classes
#include "Vector.h"
#include "Path.h"
#include "Maze.h"
#include "VirtualMaze.h"

enum IRWall{
    F, DF, LF , RF
};


#define sideWidth 18

class Mouse{
    
    
    
    
public:
    
    Mouse();
    
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
    
    
    
    
    bool isWall(IRWall dir);
    
    bool isWall(Direction dir);
    
    void faceDir(Direction dir);
    
    void Move(dirVector dir);
    
    bool exploreMaze();
    
    bool followPath(Path path);
    
    bool gotoNode(Node destination);
    
    void draw();
    
   
    
    
    
private:
    
    bool _followUntillBroken(Path path);
    
    Position _position;
    
    Node _center;
    
    double _heading;
    
    Maze maze;
    
    bool mazeFullyExplored;
    
    VirtualMaze virmaze;
    
    Path bestPath;
    
};

#endif /* Mouse_hpp */
