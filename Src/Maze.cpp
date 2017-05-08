//
//  Maze.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 4/23/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Maze.h"
/* node to self i am stuck here will figure it out next time i get back to it*/
Maze::Maze(){
    
    resetMaze();
    
}






Maze::~Maze(){
    
    
    
}







std::unordered_map<Node,std::vector<Node>,NodeHasher>  Maze::getMaze() const{
    
    return maze;
}

//Manhatten style distance between two nodes
float Maze::movementCost(const Node& from, const Node& to) const{
    
    return  sqrt(pow(abs(from.x()-to.x()),2) + pow(abs(from.y()-to.y()),2));
    
}








Path Maze::makePath(Path& path, const Node& destination){
    
    if (parent[path.start()]!=destination) {
        
        path.add(parent[path.start()]);
    }
    
    return path;
    
}











//ToDo have this return a path type
//Need to creat path class.
Path Maze::findPath(const Node& from, const Node& to){
    
    PriorityQueue toBeExplored;
    
    toBeExplored.put(from, 0);
    
    parent[from] = from;
    
    explored[from] = true;
    
    
    while (!toBeExplored.empty()) {
        
        Node currentNode = toBeExplored.get();
        
        if (currentNode == to) {
            break;
        }
        
        
        for(Node neighbour : getNeighbour(currentNode)){
            
            float newCost = cost[currentNode] +  movementCost(currentNode, neighbour);
            
            if ( !cost.count(neighbour) || newCost < cost[neighbour]) {
                
                parent[neighbour] = currentNode;
                
                cost[neighbour] = newCost;
                
                float priority = newCost + movementCost(neighbour, to);
                
                toBeExplored.put(neighbour, priority);
                
                
            }
        }
    }
    
    Node parfent = to;
    
   
  
    
    std::cout <<"****************************"<< std::endl;
    std::cout <<to.returnString()<< std::endl;
    std::cout <<"****************************"<< std::endl;
    
    
    while (true) {
        
    
        std::cout << "from " << parfent.returnString() <<"  to " << parent[parfent].returnString() << std::endl;
        
        parfent = parent[parfent];
        
        if (parfent == from) {
            std::cout <<"go here"<< std::endl;
            break;
        }
        
    }
    
    Path path(from);
    
    return makePath(path, to);
    
}








bool Maze::isvalidNode(const Node& node){
    
    return (node.x() <= mazeWidth && node.x() > 0 ) && (node.y() <= mazeHeight && node.y() > 0 );
    
}








std::vector<Node> Maze::getNeighbour(const Node& location){
    
    std::vector<Node> temp;
    
    
    
    Node holder;
    
    for (int x=-1; x < 2 ; x++) {
        
        
        for (int y = -1; y < 2; y++) {
            
           
            
            holder = Node( (location.x() + x ), (location.y() + y) );
            
            
            
            if (isvalidNode(holder) && location!= holder) {
                
                temp.push_back(holder);

            }
      
        }
   
    }

    
    return temp;
    
    
}








std::vector<Node> Maze::getStoredNeighbour(const Node& location){
    
    return maze[location];
}











Node Maze::getNeigbour(const Node& a, Direction dir){
    
    switch (dir) {
        case N:
            return Node(a.x(),a.y()+1);
            break;
        case NE:
            return Node(a.x()+1,a.y()+1);
            break;
        case E:
            return Node(a.x()+1,a.y());
            break;
        case SE:
            return Node(a.x()+1,a.y()-1);
            break;
        case S:
            return Node(a.x(),a.y()-1);
            break;
        case SW:
            return Node(a.x()-1,a.y()-1);
            break;
        case W:
            return Node(a.x()-1,a.y());
            break;
        case NW:
            return Node(a.x()-1,a.y()+1);
            break;
            
    }
    
}








bool Maze::isNeigbour(const Node& a, Direction dir){
    
    return areNeighbours(a, getNeigbour(a, dir));
    
}












void Maze::setExplored(const Node& location){
    
    explored[location] = true;
    
}







bool Maze::isExplored(const Node& location)const{
    

    return explored.at(location);
    
}






void Maze::removeNeighbour(const Node& current, const Node& toBeRemoved){
    
    
    
    switch (current.whichSide(toBeRemoved)) {
        case N:
            
            if (isNeigbour(current, E)) {
                
                removeNeighbour(current, getNeigbour(current, NE));
                
            } else if(isNeigbour(current, W)){
                
                removeNeighbour(current, getNeigbour(current, NW));
                
            }
            
            break;
            
        case E:
            
            if (isNeigbour(current, N)) {
                
                removeNeighbour(current, getNeigbour(current, NE));
                
            } else if(isNeigbour(current, S)){
                
                removeNeighbour(current, getNeigbour(current, SE));
                
            }
            
            break;
        case S:
            
            if (isNeigbour(current, E)) {
                
                removeNeighbour(current, getNeigbour(current, SE));
                
            } else if(isNeigbour(current, W)){
                
                removeNeighbour(current, getNeigbour(current, SW));
                
            }
            
            break;
        case W:
            
            if (isNeigbour(current, N)) {
                
                removeNeighbour(current, getNeigbour(current, NW));
                
            } else if(isNeigbour(current, W)){
                
                removeNeighbour(current, getNeigbour(current, NW));
                
            }
            
            break;
            
        default:
            break;
    }
    
        
        maze[current].erase(std::remove(maze[current].begin(), maze[current].end(), toBeRemoved), maze[current].end());
        
        
        maze[toBeRemoved].erase(std::remove(maze[toBeRemoved].begin(), maze[toBeRemoved].end(), current), maze[toBeRemoved].end());
        

        
        
    
    
    
    
}








void Maze::addNeighbour(const Node& current, const Node& toBeAdded){
    
    if (current != toBeAdded && isvalidNode(current) && isvalidNode(toBeAdded)) {
        
    maze[current].push_back(toBeAdded);
    maze[toBeAdded].push_back(current);
        
        
    }
}







void Maze::removeNode(const Node& toBeRemoved){
    
    maze.erase(toBeRemoved);
    
}








void Maze::addNode(const Node& toBeAdded){
    
    std::vector<Node> temp;
    
    maze.emplace(toBeAdded,temp);
    
}







void Maze::addNode(const Node& toBeAdded, std::vector<Node> neighbour){
    
    maze.emplace(toBeAdded,neighbour);
    
}







bool Maze::areNeighbours(const Node& a, const Node& b){
   
    return (std::find(maze[a].begin(), maze[a].end(), b) != maze[a].end()) |
           (std::find(maze[b].begin(), maze[b].end(), a) != maze[b].end());
    
    
}






void Maze::resetMaze(){
    
    Node temp;
    
    std::vector<Node> neb;
    
    for(int x = mazeWidth; x > 0  ; x-- ){
        
        
        for (int y = mazeHeight ; y >0 ; y--) {
            
            temp = Node(x,y);
            
            neb = getNeighbour(temp);
           
            maze.emplace(temp,neb);
            
            
        }
        
    }
    
}









