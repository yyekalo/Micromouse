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
#include "Vector.h"
#include <unordered_map>


class Maze
{
 
public:
    
    Maze();
    
    ~Maze();
    
    Node* getNode(Node location);
    
    std::vector<Node> getNeighbour(Node location);
    
    Node* getNeighbour(Node location, Direction);
    
    void setExplored(Node location);
    
    bool isExplored(Node location) const;

    
private:
    
    void resetMaze();
    
    std::unordered_map<Node,std::vector<Node>,NodeHasher> maze;
    
    std::unordered_map<Node, float,NodeHasher>  cost;
    
    std::unordered_map<Node, Node,NodeHasher>  parent;
    
    std::unordered_map<Node, bool,NodeHasher>  explored;

    
    
    
};


#endif /* Maze_hpp */
