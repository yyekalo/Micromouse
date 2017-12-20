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










bool Maze::mazeExplored(){
    
    bool temp = true;
    
    for (auto isexp : explored) {
        
        if (!isexp.second ) {
            
            temp = false;
            break;
        }
    }
    
    return temp;
}












//return Path from (from) to the destination to.
Path Maze::findPath(const Node& from, const Node& to,bool diagnoalAllowed){
    
    PriorityQueue toBeExplored;
    
    toBeExplored.put(from, 0);
    
    std::unordered_map<Node, float,NodeHasher>  cost;
    
    std::unordered_map<Node, Node,NodeHasher>  parent;
    
    
    parent[from] = from;
    
    explored[from] = true;
    
    
    while (!toBeExplored.empty()) {
        
        
        Node currentNode = toBeExplored.get();
        
        //std::cout << "currentNode "  << currentNode.returnString() << std::endl;
        explored[currentNode] = true;
        
       
        
        if (currentNode == to) {
            
           
            break;
        }
        
        
        
        for(Node neighbour : getStoredNeighbour(currentNode)){
            
           
            
            if (!diagnoalAllowed && (currentNode.whichSide(neighbour)== NE || currentNode.whichSide(neighbour)== SE ||
                currentNode.whichSide(neighbour)== SW ||currentNode.whichSide(neighbour)== NW ))
            {
                
                continue;
            }
            
            float newCost = cost[currentNode] +  movementCost(currentNode, neighbour);
            
            
            if ( !cost.count(neighbour) || newCost < cost[neighbour]) {
                
                parent[neighbour] = currentNode;
                
                cost[neighbour] = newCost;
                
                float priority = newCost + movementCost(neighbour, to);
                                
                toBeExplored.put(neighbour, priority);
                
                
                
                
            }
        }
    }
    
    
   
    if (explored[to]==false) {
        
        return Path(Node(0,0));
        
    }
    
    
    
    
    /*
     This is where to edit if you change the path class.
     */
    
    Path  path(to);
    
    while (path.start() != from) {
        path.add(parent[path.start()]);
    }
    
    
    
    explored.clear();
    
    return path;  
    
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












std::vector<Direction> Maze::missingNeigbour(const Node& location){
    
    std::vector<Direction>  temp;
    Direction side;
    
    
    
    for(auto neigbour : getNeighbour(location)){
        
        if(!areNeighbours(location, neigbour)){
            
            side = location.whichSide(neigbour);
            
            if (side==N || side==E || side==S || side==W) {
                
                temp.push_back(location.whichSide(neigbour));
                
            }
            
        }
        
    }
    
    return temp;
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






void Maze::_removeNeighbour(const Node& current, const Node& toBeRemoved){
    
    maze[current].erase(std::remove(maze[current].begin(), maze[current].end(), toBeRemoved), maze[current].end());
    
    
    maze[toBeRemoved].erase(std::remove(maze[toBeRemoved].begin(), maze[toBeRemoved].end(), current), maze[toBeRemoved].end());

}






void Maze::removeNeighbour(const Node& current, const Node& toBeRemoved){
    
    
    
    switch (current.whichSide(toBeRemoved)) {
        case N:
            
            if (!isNeigbour(current, E) || !isNeigbour(getNeigbour(current, E), N)) {
                
                _removeNeighbour(current, getNeigbour(current, NE));
                
            }
            
            if(!isNeigbour(current, W) || !isNeigbour(getNeigbour(current, W), N)){
                
                _removeNeighbour(current, getNeigbour(current, NW));
                
            }
            
            
            
            break;
            
        case E:
            
            if (!isNeigbour(current, N) || !isNeigbour(getNeigbour(current, N), E)) {
                
                _removeNeighbour(current, getNeigbour(current, NE));
                
            }
            
            if(!isNeigbour(current, S) || !isNeigbour(getNeigbour(current, S), E)){
                
                _removeNeighbour(current, getNeigbour(current, SE));
                
            }
            
            break;
        case S:
            
            if (!isNeigbour(current, E) || !isNeigbour(getNeigbour(current, E), S)) {
                
                _removeNeighbour(current, getNeigbour(current, SE));
                
            }
            
            if(!isNeigbour(current, W) || !isNeigbour(getNeigbour(current, W), S)){
                
                _removeNeighbour(current, getNeigbour(current, SW));
                
            }
            
            break;
        case W:
            
            if (!isNeigbour(current, N) || !isNeigbour(getNeigbour(current, N), W)) {
                
                _removeNeighbour(current, getNeigbour(current, NW));
                
            }
            
            if(!isNeigbour(current, S) || !isNeigbour(getNeigbour(current, S), W)){
                
                _removeNeighbour(current, getNeigbour(current, SW));
                
            }
            break;
            
        default:
            break;
    }
    
    
    
    
    
    
    //This is for the other Neigbour that is being removed
    
    switch (toBeRemoved.whichSide(current)) {
        case N:
            
            if (!isNeigbour(toBeRemoved, E) || !isNeigbour(getNeigbour(toBeRemoved, E), N)) {
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, NE));
                
            }
            
            if(!isNeigbour(toBeRemoved, W) || !isNeigbour(getNeigbour(toBeRemoved, W), N)){
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, NW));
                
            }
            
            
            
            break;
            
        case E:
            
            if (!isNeigbour(toBeRemoved, N) || !isNeigbour(getNeigbour(toBeRemoved, N), E)) {
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, NE));
                
            }
            
            if(!isNeigbour(toBeRemoved, S) || !isNeigbour(getNeigbour(toBeRemoved, S), E)){
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, SE));
                
            }
            
            break;
        case S:
            
            if (!isNeigbour(toBeRemoved, E) || !isNeigbour(getNeigbour(toBeRemoved, E), S)) {
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, SE));
                
            }
            
            if(!isNeigbour(toBeRemoved, W) || !isNeigbour(getNeigbour(toBeRemoved, W), S)){
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, SW));
                
            }
            
            break;
        case W:
            
            if (!isNeigbour(toBeRemoved, N) || !isNeigbour(getNeigbour(toBeRemoved, N), W)) {
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, NW));
                
            }
            
            if(!isNeigbour(toBeRemoved, S) || !isNeigbour(getNeigbour(toBeRemoved, S), W)){
                
                _removeNeighbour(toBeRemoved, getNeigbour(toBeRemoved, SW));
                
            }
            break;
            
        default:
            break;
    }

    
    _removeNeighbour(current, toBeRemoved);
    
    
}








void Maze::removeNeighbour(const Node& current, Direction dir){
    
    
    removeNeighbour(current,getNeigbour(current, dir));

    
}










void Maze::addNeighbour(const Node& current, const Node& toBeAdded){
    
    if (current != toBeAdded && isvalidNode(current) && isvalidNode(toBeAdded) && !areNeighbours(current, toBeAdded)) {
        
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
    
    maze.clear();
    
    for(int x = mazeWidth; x > 0  ; x-- ){
        
        
        for (int y = mazeHeight ; y >0 ; y--) {
            
            temp = Node(x,y);
            
            neb = getNeighbour(temp);
           
            maze.emplace(temp,neb);
            
            
        }
        
    }
    
}















void Maze::print(const Node& temp){
    
    for(auto temp : getStoredNeighbour(temp)){
        
        std::cout << temp.returnString()  << std::endl;
    
    }
    
     std::cout << "DD" << std::endl;
}




