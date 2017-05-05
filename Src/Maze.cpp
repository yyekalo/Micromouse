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




//Manhatten style distance between two nodes
float Maze::movementCost(const Node& from, const Node& to) const{
    
    return  sqrt(pow(abs(from.x()-to.x()),2) + pow(abs(from.y()-to.y()),2));
    
}







//ToDo have this return a path type
//Need to creat path class.
void Maze::findPath(const Node& from, const Node& to){
    
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
    
}








bool Maze::isvalidNode(Node& node){
    
    return (node.x() < mazeWidth && node.x() > 0 ) && (node.y() < mazeHeight && node.y() > 0 );
    
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









void Maze::setExplored(const Node& location){
    
    explored[location] = true;
    
}







bool Maze::isExplored(const Node& location)const{
    

    return explored.at(location);
    
}






void Maze::removeNeighbour(const Node& current, const Node& toBeRemoved){
    
    maze[current].erase(std::remove(maze[current].begin(), maze[current].end(), toBeRemoved), maze[current].end());
    
}








void Maze::addNeighbour(const Node& current, const Node& toBeAdded){
    
    maze[current].push_back(toBeAdded);
    
}







void Maze::removeNode(const Node& toBeRemoved){
    
    maze.erase(toBeRemoved);
    
}







void Maze::resetMaze(){
    
    Node temp;
    
    std::vector<Node> neb;
    
    for(int x = 0 ; x < mazeWidth ; x++ ){
        
        
        for (int y = 0 ; y< mazeHeight ; y++) {
            
            temp = Node(x,y);
            
            neb = getNeighbour(temp);
           
            maze.emplace(temp,neb);
            
            
        }
        
    }
    
}









