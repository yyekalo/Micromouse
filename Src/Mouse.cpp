//
//  Mouse.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Mouse.h"




Mouse::Mouse();








Mouse::Mouse(Node currentPosition, Direction currentDirection, Node intCenter){
    
    position = currentPosition;
    
    center = intCenter;
    
    heading = currentDirection;
    
    maze = Maze();
    
    
}








Mouse::~Mouse(){
    
}








bool Mouse::isWall(Direction dir){
    
    
}







void faceDir(Direction dir){
    
    
    
}







void Move(dirVector dir){
    
}








bool Mouse::exploreMaze(){
    
    Path temp = maze.findPath(position, center);
    
    
    while (!temp.empty()) {
        
        
         followUntillBroken(temp);
        
        temp = maze.findPath(position, center);
        
        
        
    }
    
    
    
    
    
    
}








bool Mouse::followPath(Path path){
    
    
    
    
    
    
    
    
}









bool Mouse::followUntillBroken(Path path){
    
   Node nextPosition = path.nextNode();
    
    if (isWall(E)) {
        
        maze.removeNeighbour(position, E);
    }
    
    
    
    if (isWall(W)) {
        
        maze.removeNeighbour(position, W);
        
    }
    
    
    
    if(isWall(position.whichSide(nextPosition))){
        
        maze.removeNeighbour(position, nextPosition);
        
        return false;
    }
    
    
    Move(<#dirVector dir#>)
    
    
    
    
    
    
    
    
    
    
}





