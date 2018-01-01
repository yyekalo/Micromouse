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
    
    _start = Node(1,1);
    
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
    
    
    
    virmaze.animate(positionNode(), dir.getNode(positionNode()));
    
    maze.setExplored(positionNode());
    
    setPosition(dir.getNode(positionNode()));
    
}








bool Mouse::exploreMaze(){
    
    Path temp,temp4;
    
    virmaze.drawMaze(maze);
    
    gotoNode(_center);
    
    gotoNode(getExplored(maze.findPath(Node(1,1),positionNode(),false)));
    
    
    do{
        
        Node temp1,temp2;
        
        
        virmaze.drawPath(temp,sf::Color::Black);
        
        temp = maze.findPath(_start, _center,false);
        std::cout <<"******************************" << std::endl;
    
       
        
        virmaze.drawPath(temp,sf::Color::White);
        
        temp1 = getExplored(maze.findPath(_start, _center,false));
 
        gotoNode(getExplored(maze.findPath(_start, _center,false)));
        
        //_followUntillBroken(maze.findPath(positionNode(), getExplored(maze.findPath(_center, positionNode())),false));
        Node tt = positionNode();
        
       temp4 = maze.findPath(_center, positionNode(),false);
        
        temp2 = getExplored(maze.findPath(_center, positionNode(),false));
        
        maze.findPath(_center, positionNode(),false).print();
        
        gotoNode(getExplored(maze.findPath(_center, positionNode(),false)));
        
        Node t;
        
        while (!temp.empty()) {
            
            t = temp.nextNode();
            
            std::cout << t.returnString() <<  maze.isExplored(t) << "    ";
            
        }
        std::cout << std::endl;
        
         std::cout <<"******************************" << std::endl;
    }while (!isExplored(maze.findPath(_start, _center,false)));
    
     std::cout << "finished drawing all" << std::endl;
    
    _followUntillBroken(maze.findPath(positionNode(), _start));
    
    
    
    
    virmaze.drawMaze(maze,sf::Color::Green);
    virmaze.display();
    virmaze.drawPath(maze.findPath(Node(1,1), _center,false),sf::Color::Cyan);
    virmaze.display();
    virmaze.drawPath(Node(1,1),Node(8,8),false,sf::Color::Yellow);
    virmaze.display();
    virmaze.drawNode(virmaze.getCenter(positionNode()), HeadingDir());
    
    
    
   
    
    
    
    while (true) {
        
    }
    
    
    return true;
    
    
}








bool Mouse::followPath(Path path){
    
    
    return true;
    
    
}








//Test this function more
//TODO:- i might implment time out for this
bool Mouse::gotoNode(Node destination){
    
    if (Node(0,0)==destination) {
        return false;
    }
    
    Path temp;
    
    while (positionNode()!= destination) {
        
        temp = maze.findPath(positionNode(), destination,false);
        
        virmaze.drawPath(temp,sf::Color::Magenta);
        
        _followUntillBroken(temp);
        
        virmaze.drawPath(temp,sf::Color::Black);
        
        
        
    }
    
    return true;
}







//TODO: edit this to work on the real micromouse
bool Mouse::_followUntillBroken(Path path){
    
    
    
    while (!path.empty()) {
        
        
        

        //TODO:- implment realistic exploration
        //The micromouse can only check left right find and two diagonals
        
        
        if (isWall(N)) {
            
            maze.removeNeighbour(positionNode(), N);
            
            virmaze.drawWall(positionNode(), N,sf::Color::Green);
            
        }
        
        
        if (isWall(E)) {
            
            maze.removeNeighbour(positionNode(), E);
            
            virmaze.drawWall(positionNode(), E,sf::Color::Green);
            
        }

        
        if (isWall(S)) {
            
            maze.removeNeighbour(positionNode(), S);
            
            virmaze.drawWall(positionNode(), S,sf::Color::Green);
            
        }

        
        if (isWall(W)) {
            
            maze.removeNeighbour(positionNode(), W);
            
            virmaze.drawWall(positionNode(), W,sf::Color::Green);
            
        }
        
        
        
        //This need to change it need to give me 180 degree of what it is giving me.
        
        
        if (isWall(path.peek().Dir())) {
            return false;
        }
            
        usleep(100000);
        Move(path.next());
        
        
        
    }
    
    
    
    
    return true;
}








void Mouse::draw(){
    
    virmaze.clear();
    
    virmaze.drawBackground();
    
    virmaze.drawMaze(sf::Color::Color(0,255,255,50));
    
    virmaze.drawMaze(maze,sf::Color::Red);
    
    virmaze.display();
    
    virmaze.dump();


    
    
    
}






bool Mouse::isExplored(Path path){
    
    Node temp;
    
    while (!path.empty()) {
        
        temp = path.nextNode();
        
        if (!maze.isExplored(temp)) {
            
            return false;
            
        }
    }
    
    return true;
    
}






Node Mouse::getExplored(Path path){
    
    
    Node temp = path.start();
    
    if(isExplored(path)){
        
        return  Node(0,0);
        
    }
        
    while (maze.isExplored(path.peekNode())){
        
        temp = path.nextNode();
        
    }
        
        
    
    return  temp ;
    
    
}









