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
#include <vector>

//To be removed later here just for debuging purpose only
#include <iostream>

#define mazeHeight 16
#define mazeWidth 16


class Maze
{
 
public:
    
    Maze();
    
    ~Maze();
    
    std::vector<Node> getNeighbour(const Node& location);
    
    
    void setExplored(const Node& location);
    
    bool isExplored(const Node& location) const;
    
    void removeNeighbour(const Node& current, const Node& toBeRemoved);
    
    void addNeighbour(const Node& current, const Node& toBeAdded);
    
    void removeNode(const Node& toBeRemoved);

    
private:
    
    bool isvalidNode(Node& node);
    
    void resetMaze();
    
    std::unordered_map<Node,std::vector<Node>,NodeHasher> maze;
    
    std::unordered_map<Node, float,NodeHasher>  cost;
    
    std::unordered_map<Node, Node,NodeHasher>  parent;
    
    std::unordered_map<Node, bool,NodeHasher>  explored;

    
    
    
};


#endif /* Maze_hpp */
