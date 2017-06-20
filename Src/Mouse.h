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




#define sideWidth 18

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
    
    
    //Hight level functions
    
    bool exploreMaze();
    
    
    void draw();
    
    
    
    //Movment functions

    
    void faceDir(Direction dir);
    
    void Move(dirVector dir);
    
    bool followPath(Path path);
    
    bool gotoNode(Node destination);
    
    //information retriving functions
    
    bool isWall(Direction dir);
    
    bool pathVisited(Path path);

    
   
    
    
    
private:
    
    bool _followUntillBroken(Path path);
    
    
    //current Mouse Bot state
    
    Position _position;
    
    double _heading;
    
    
   
    
    //Maze info
    Maze maze;
    
    Node _center = Node(8,8);
    
    bool mazeFullyExplored;
    
    Path bestPath;

    
    
    /*only if in simulation. I might have to remove it later 
     or use Macro to not declare it.
     */
    VirtualMaze virmaze;

    
};

#endif /* Mouse_hpp */
