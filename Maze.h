//
//  Maze.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 4/23/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include "Node.h"
#include "Vector.h"

class Maze
{
 
public:
    
    Maze();
    
    ~Maze();
    
    Node* getNode(Location<int> location);
    
    std::vector<Node> getNeighbour(Location<int> location);
    
    Node* getNeighbour(Location<int> location, Direction);
    
    void setExplored(Location<int> location);
    
    bool isExplored(Location<int> location) const;

    
private:
    
    
    std::vector<Location<int>> maze;
    
    
};


#endif /* Maze_hpp */
