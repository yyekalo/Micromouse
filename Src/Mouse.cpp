//
//  Mouse.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "Mouse.h"





Mouse::Mouse(Position currentPosition, Direction currentDirection, Node intCenter){
    
    _position = currentPosition;
    
    _center = intCenter;
    
    _heading = currentDirection;
    
    maze = Maze();

    maze.resetMaze();
    
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
    
    
    return Node(floor(_position.x() / sideWidth)+1 , floor(_position.y() / sideWidth)+1);
    
}







void Mouse::setPosition(Node position){
    

    _position = Position(((position.x() * sideWidth)-(sideWidth/2)) , ((position.y() * sideWidth)-(sideWidth/2)));
    
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









bool Mouse::isWall(Direction dir){
    
    return virmaze.isWall(positionNode(), dir);
    
}










void faceDir(Direction dir){
    
    std::cout << "Facing " << dir << std::endl;
    
}







void Mouse::Move(dirVector dir){
    
//only in pc
    virmaze.drawMaze(sf::Color());
    
    virmaze.animate(positionNode(), dir.getNode(positionNode()));
    
    virmaze.drawMaze(maze);
    
    //upto here
    
    
    setPosition(dir.getNode(positionNode()));
    
}








bool Mouse::exploreMaze(){
    
    
    
    Path temp;
    
    
    do{
        
        
        temp = maze.findPath(positionNode(), _center,false);
        
        temp.print();
        
         _followUntillBroken(temp);
        
        
    } while (positionNode()!=_center);
    

    do{
        
        
        temp = maze.findPath(positionNode(), Node(1,1),false);
        
        temp.print();
        
        _followUntillBroken(temp);
        
        
    } while (positionNode()!=Node(1,1));
    
   
    temp = maze.findPath(Node(1,1), _center);
    
    virmaze.drawPath(temp,sf::Color::Blue);
    
    temp = maze.findPath(_center, Node(1,1));
    
    virmaze.drawPath(temp,sf::Color::Green);
    
    virmaze.display();
    
    while (true) {
        
    }
    
    
    return true;
    
    
}








bool Mouse::followPath(Path path){
    
    
    return true;
    
    
}








//Test this function more
bool Mouse::gotoNode(Node destination){
    
    
   return  _followUntillBroken(maze.findPath(positionNode(), destination));
    
}








bool Mouse::_followUntillBroken(Path path){
    
    
    
    while (!path.empty()) {
        
        std::cout << "current posistion " <<positionNode().returnString() << std::endl;
        

        //TODO:- implment realistic exploration
        //The micromouse can only check left right find and two diagonals
        
        
        if (isWall(N)) {
            
            maze.removeNeighbour(positionNode(), N);
            
        }
        
        
        if (isWall(E)) {
            
            maze.removeNeighbour(positionNode(), E);
            
        }

        
        if (isWall(S)) {
            
            maze.removeNeighbour(positionNode(), S);
            
        }

        
        if (isWall(W)) {
            
            maze.removeNeighbour(positionNode(), W);
            
        }
        
        
        
        //This need to change it need to give me 180 degree of what it is giving me.
        if (isWall(path.peek().Dir())) {
            return false;
        }
            
        
        Move(path.next());
        
        if(path.empty()){
            
            std::cout << "reached center" << std::endl;
            
        }
        
    }
    
    
    
    
    return true;
}








void Mouse::draw(){
    
    virmaze.clear();
    
    virmaze.drawBackground();
    
    virmaze.drawMaze(sf::Color::Color(0,255,255,50));
    
    virmaze.drawMaze(maze,sf::Color::Red);
    
    virmaze.drawPath(bestPath,sf::Color::Green);
    
    virmaze.drawPath(maze.findPath(positionNode(), _center),sf::Color::White);
    
    virmaze.display();
    
    virmaze.dump();


    
    
    
}










