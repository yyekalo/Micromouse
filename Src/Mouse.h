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


class Mouse{
    
    
    
    Mouse();
    
    Mouse(Node currentPosition=Node(1,1), Direction currentDirection = N,Node center=Node(8,8));
    
    ~Mouse();
    
    bool isWall(Direction dir);
    
    void faceDir(Direction dir);
    
    void Move(dirVector dir);
    
    bool exploreMaze();
    
    bool followPath(Path path);
    
    
    
   
    
    
    
private:
    
    bool followUntillBroken(Path path);
    
    Node position;
    
    Node center;
    
    Direction heading;
    
    
    Maze maze;
    
    
};

#endif /* Mouse_hpp */
