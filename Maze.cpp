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









bool isvalidNode(Node& node){
    
    return (node.x() < mazeWidth && node.x() > 0 ) && (node.y() < mazeHeight && node.y() > 0 );
    
}








std::vector<Node> getNeighbour(const Node& location){
    
    std::vector<Node> temp;
    
    
    
    Node holder;
    
    for (int x=-1; x <= 2 ; x++) {
        
        
        for (int y = -1; y <= 2; y++) {
            
            holder = Node( (location.x() + x ), (location.y() + y) );
            
            std::cout << "potentional" << std::endl;
            
            std::cout << holder.returnString()<< std::endl;
            
            if (isvalidNode(holder) && location==holder) {
                
                temp.push_back(holder);

            }
      
        }
   
    }
    
    std::cout << "##########################" << std::endl;
    
    std::cout << holder.returnString()<< std::endl;

    std::cout << "***************************" << std::endl;

    
    for(auto m : temp)
    {
        
        std::cout << m.returnString()<< std::endl;
    }
    
    std::cout << "***************************" << std::endl;
    
    return temp;
    
    
}









void Maze::setExplored(const Node& location){
    
    explored[location] = true;
    
}







bool Maze::isExplored(const Node& location)const{
    

    return explored.at(location);
    
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









