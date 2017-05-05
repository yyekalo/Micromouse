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
#include <queue>
#include <math.h>

//To be removed later here just for debuging purpose only
#include <iostream>


#define mazeHeight 16
#define mazeWidth 16

/*This queue wraper struct code and the findPath function which implment the A* algorithm is also adaptation form Amit Patel @ https://twitter.com/redblobgames

 */
struct PriorityQueue {
    typedef std::pair<float, Node> PQElement;
    std::priority_queue<PQElement, std::vector<PQElement>,
    std::greater<PQElement>> elements;
    
    inline bool empty() const { return elements.empty(); }
    
    inline void put(Node item, float priority) {
        elements.emplace(priority, item);
    }
    
    inline Node get() {
        Node best_item = elements.top().second;
        elements.pop();
        return best_item;
    }
};




class Maze
{
 
public:
    
    Maze();
    
    ~Maze();
    
    float movementCost(const Node& from, const Node& to) const;
    
    void findPath(const Node& from , const Node& to );
    
    std::vector<Node> getNeighbour(const Node& location);
    
    
    void setExplored(const Node& location);
    
    bool isExplored(const Node& location) const;
    
    void removeNeighbour(const Node& current, const Node& toBeRemoved);
    
    void addNeighbour(const Node& current, const Node& toBeAdded);
    
    void removeNode(const Node& toBeRemoved);
    
    void addNode(const Node& toBeAdded);
    
    void addNode(const Node& toBeAdded, std::vector<Node> neighbour);

    
private:
    
    bool isvalidNode(Node& node);
    
    void resetMaze();
    
    std::unordered_map<Node,std::vector<Node>,NodeHasher> maze;
    
    std::unordered_map<Node, float,NodeHasher>  cost;
    
    std::unordered_map<Node, Node,NodeHasher>  parent;
    
    std::unordered_map<Node, bool,NodeHasher>  explored;

    
    
    
};













#endif /* Maze_hpp */
