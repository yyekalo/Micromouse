//
//  Mouse.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Mouse.h"




Mouse::Mouse(){
    
    
    virmaze.generateMaze();
    
    virmaze.drawAll();
    
    virmaze.run();
    
    virmaze.display();
    
    virmaze.dump();
    
    
}








Mouse::Mouse(Position currentPosition, Direction currentDirection, Node intCenter){
    
    _position = currentPosition;
    
    _center = intCenter;
    
    _heading = currentDirection;
    
    maze = Maze();
    
    virmaze.generateMaze();
    
    virmaze.run();
    
    exploreMaze();
    
    
    
}








Mouse::~Mouse(){
    
}







Position Mouse::position(){
    
    return _position;
}







Node      Mouse::positionNode(){
    
    return Node(_position.x() / sideWidth , _position.y() / sideWidth);
    
}







void Mouse::setPosition(Node position){
    
    _position = Position(position.x() * sideWidth , position.y() * sideWidth);
    
}







void Mouse::sePosition(Position position){
    
    _position = position;
}







double    Mouse::Heading(){
    
    return _heading;
}







Direction  Mouse::HeadingDir(){
    
    return static_cast<Direction>( _heading / 45);
    
}







void Mouse::setHeading(Direction dir){
    
    _heading = dir * 45;
    
}







void Mouse::setHeading(double dir){
    
    _heading = dir;
    
}







bool Mouse::isWall(IRWall dir){
    
    switch (dir) {
            
            
        case F:
            
            return  virmaze.isWall(positionNode(), N);
            
            break;
            
        case DF:
            
            return virmaze.isWall(maze.getNeigbour(positionNode(), N), N);
            
            break;
            
        case LF:
            
           return virmaze.isWall(maze.getNeigbour(positionNode(), N), W);
            
            break;
            
        case RF:
            
            return virmaze.isWall(maze.getNeigbour(positionNode(), N), E);
            
            break;
            
    }
    
    
}








bool Mouse::isWall(Direction dir){
    
    return !maze.areNeighbours(positionNode(), maze.getNeigbour(positionNode(), dir));
    
}










void faceDir(Direction dir){
    
    std::cout << "Facing " << dir << std::endl;
    
}







void Mouse::Move(dirVector dir){
    
    std::cout << "Moving this wasy " << dir.Dir() << dir.Mag() << std::endl;

    
}








bool Mouse::exploreMaze(){
    
    
    
    Path temp;
    
    
    do{
        
        std::cout << "got here " << std::endl;
        
        temp = maze.findPath(positionNode(), _center);

         _followUntillBroken(temp);
        
               temp.print();

    } while (!temp.empty());
    
    
    
    return true;
    
    
}








bool Mouse::followPath(Path path){
    
    
    
    
    
    return true;
    
    
}









bool Mouse::gotoNode(Node destination){
    
    
   return  _followUntillBroken(maze.findPath(positionNode(), destination));
    
}








bool Mouse::_followUntillBroken(Path path){
    
    while (!path.empty()) {
        
    
    
   Node nextPosition = path.peekNode();
    
    if (isWall(F)) {
        
        maze.removeNeighbour(positionNode(), N);
    }
    
    
    
    if (isWall(DF)) {
        
        maze.removeNeighbour(maze.getNeigbour(positionNode(), N), N);
        
    }
    
        
    if (isWall(LF)) {
            
        maze.removeNeighbour(maze.getNeigbour(positionNode(), W), N);
            
    }
    
    if (isWall(RF)) {
            
            maze.removeNeighbour(maze.getNeigbour(positionNode(), E), N);
            
    }
    
    
    if(isWall(positionNode().whichSide(nextPosition))){
        
        maze.removeNeighbour(positionNode(), nextPosition);
        
        return false;
    }
    
    setPosition(path.peekNode());
    
    Move(path.next());
        
        draw();
        
    
    }
    
    
    return true;
    
}








void Mouse::draw(){
    
    virmaze.clear();
    
    virmaze.drawBackground();
    
    virmaze.drawMaze(sf::Color::Color(0,255,255,50));
    
    virmaze.drawMaze(maze,sf::Color::Red);
    
   // virmaze.drawPath(bestPath,sf::Color::Green);
    
    virmaze.drawPath(maze.findPath(positionNode(), _center),sf::Color::White);
    
    virmaze.display();
    
    virmaze.dump();


    
    
    
}










