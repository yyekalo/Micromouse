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








bool Mouse::isWall(Direction dir){
    
    cout << "Is wall infront " << positionNode().returnString() << " facing " << dir <<" "<< virmaze.isWall(positionNode(), dir)<<endl;
    return virmaze.isWall(positionNode(), dir);
   
    
}










void faceDir(Direction dir){
    
    std::cout << "Facing " << dir << std::endl;
    
}







void Mouse::Move(dirVector dir){
    
    
    
   


    setPosition(dir.getNode(positionNode()));
    
    std::cout << " at" << positionNode().returnString()<< std::endl;
    
    
    virmaze.clear();
    virmaze.drawBackground();
    virmaze.drawMaze(maze);
    virmaze.display();
    virmaze.dump();
    
    
}








bool Mouse::exploreMaze(){
    
    cout << " Center is though as " << _center.returnString() << endl;

    
    while (positionNode()!=_center) {
        
        maze.findPath(positionNode(), _center).print();
        
      _followUntillBroken(maze.findPath(positionNode(), _center));
        
        
    
        
    }

   
    
    
    
    
    
    
    
    return true;
    
    
}











bool Mouse::_followUntillBroken(Path path){
    
    
    
    while (!path.empty()) {
        
        
        
        if (isWall(positionNode().whichSide(path.peekNode()))) {
            
            
            
            
            
            maze.removeNeighbour(positionNode(), path.peekNode());
            
            return false;
            
        }
        
        cout << " my next position " << path.peekNode().returnString() << endl;
        
        gotoNode(path.nextNode());
    
    
    }
    
    
    
    
    
    
    
    return true;
    
    
}










/*
 TODO: This function is going to be modified later on to produce smoth traversing with speed control
 */
bool Mouse::followPath(Path path){
    
    if (!pathVisited(path)) {
        
        
    }
    
    while (!path.empty()) {
        
        
        Move(path.next());
        
    }
    
    
    
    return true;
    
    
}








//TODO: review if this is a good implmentation
bool Mouse::gotoNode(Node destination){
    
    setPosition(destination);
    
    cout << "set position to be " << destination.returnString() << endl;
    
    return true; //followPath(maze.findPath(positionNode(), destination));
    
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


    
    //Temperaly storing;
    virmaze.clear();
    virmaze.drawBackground();
    virmaze.drawMaze(maze);
    virmaze.display();
    virmaze.dump();
    
    
}











bool Mouse::pathVisited(Path path){
    
    while (path.empty()) {
        
        
        
        if (!maze.explored[path.nextNode()]) {
            
            return false;
        }
        
    }
    
    
    return true;
    
}








