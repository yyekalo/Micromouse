//
//  Maze.hpp
//  lkn
//
//  Created by Yikealo Abraha  on 4/19/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include "Node.h"

class Maze {
    
public:
    
    Maze(int width=16,int height=16);
    ~Maze();
    
    
    
private:
    
    int width, height;
    
    Node* maze[width][height];
    
    
    
    
    
    
    
    
    
    
    
    
    
};

#endif /* Maze_hpp */
