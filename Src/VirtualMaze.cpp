//
//  VirtualMaze.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/5/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "VirtualMaze.h"



VirtualMaze::VirtualMaze(){
    
    maze = Maze();
    
    
    window.create(sf::VideoMode(1400,1400),"my home");
    
    drawBackground();
    
    window.display();
    
    run();
}







VirtualMaze::~VirtualMaze(){
    
    window.close();
}








//gets corrdinate in the screen adn try to find a pair of nodes that are
// adjucent to the wall clicked.
nPair VirtualMaze::getPair(int x, int y){
    
    int tempx = (x/cellWidth) + 1;
    int tempy = 16 - (y/cellWidth);
    
    Node a(tempx,tempy),b;
    
    

    
    if (abs((x%cellWidth)-(cellWidth/2)) > abs((y%cellWidth)-(cellWidth/2))) {
        
        
        
        //this is horizontal adjacent
        b = Node(((x%cellWidth)<(cellWidth/2))?tempx-1:tempx+1,tempy);
        
    }else {
        
        b = Node(tempx,((y%cellWidth)>(cellWidth/2))?tempy-1:tempy+1);
        
    }
    
    
    return (maze.isvalidNode(b) ? std::make_pair(a,b):std::make_pair(a,a));
    
    
    
}









void VirtualMaze::wallToggled(int x, int y){
    
    nPair temp = getPair(x,y);
    
    
    if( maze.areNeighbours(temp.first, temp.second)){
        
       
        maze.removeNeighbour(temp.first, temp.second);
    
        
    } else {
        
        maze.addNeighbour(temp.first, temp.second);
    
    }
    
    
}














void VirtualMaze::randomRemoveNeigbour(const Node& loc){
    
    std::vector<Node>  temp;
    
    
    for(auto neigbour: maze.getStoredNeighbour(loc)){
        
        if (loc.whichSide(neigbour)%2==0) {
            
            temp.push_back(neigbour);
        }
    }
    
    if (loc == Node(1,1)) {
        
        maze.removeNeighbour(loc, temp[rand() % 2] );
        
        return;
    }
    
    if (temp.size() != 0 && temp.size() > 2) {
        
        maze.removeNeighbour(loc, temp[rand() % temp.size()] );
        
    }
    
    
}











void VirtualMaze::generateMaze(){
    
    
    maze.resetMaze();
    
    for(auto nodes: maze.getMaze()){
        
        
       // std::cout << nodes.first.returnString() << std::endl;
        
        randomRemoveNeigbour(nodes.first);
        
        
    }
    
}









Node VirtualMaze::toScreen(const Node& location){
    
    return Node(location.x()*cellWidth,(16-location.y())*cellWidth);
    
    
}









std::vector<Direction> VirtualMaze::missingNeigbour(const Node& location){
    
    std::vector<Direction>  temp;
    Direction side;
    
    
    
    for(auto neigbour : maze.getNeighbour(location)){
        
        if(!maze.areNeighbours(location, neigbour)){
            
            side = location.whichSide(neigbour);
            
            if (side==N || side==E || side==S || side==W) {
                
            temp.push_back(location.whichSide(neigbour));
                
            }
            
        }
        
    }
    
    return temp;
}








void VirtualMaze::drawWall(const Node& location, Direction side){
    
    int x1,y1,x2=0,y2=0,tempx = 0,tempy;
    
    Node tempNode = toScreen(location);
    
    tempx = tempNode.x();
    
    tempy = tempNode.y();
    
    x1 = tempx;
    
    y1 = tempy;
    
    
    switch (side) {
        case N:
            
            x2 = tempx - cellWidth;
            y2 = tempy;
        break;
            
        case E:
            
            x2 = tempx;
            y2 = tempy + cellWidth;
            break;
            
        case S:
            
            y1 = tempy + cellWidth;
            x2 = tempx - cellWidth;
            y2 = tempy + cellWidth;
            break;
            
        case W:
            
            x1 = tempx - cellWidth;
            x2 = tempx - cellWidth;
            y2 = tempy + cellWidth;
            break;
            
        default:
            return;
            break;
    }
    
    
    
    sf::Vertex wall[] =
    {
        sf::Vertex(sf::Vector2f(x1,y1 ),sf::Color::Red),
        sf::Vertex(sf::Vector2f(x2,y2 ),sf::Color::Red),
    };
    
    
    window.draw(wall, 2, sf::Lines);
    
}














//TODO next finsih this function
//perhaps get the direction of missing Neigbour
void VirtualMaze::drawMaze(){
    
   
    for(auto pair : maze.getMaze()){
        
        for(auto dir : missingNeigbour(pair.first)){
            
            drawWall(pair.first, dir);
        }

        
    }
    
}











void VirtualMaze::drawBackground(){
    
    sf::Vertex top[] =
    {
        sf::Vertex(sf::Vector2f(2,2), sf::Color::Red),
        sf::Vertex(sf::Vector2f(1360,2),sf::Color::Red),
    };
    
    window.draw(top,2,sf::Lines);
    
    sf::Vertex bottom[] =
    {
        sf::Vertex(sf::Vector2f(1, 1360), sf::Color::Red),
        sf::Vertex(sf::Vector2f(1360, 1360),sf::Color::Red),
    };
    
    window.draw(bottom,2,sf::Lines);
    
    sf::Vertex right[] =
    {
        sf::Vertex(sf::Vector2f(1360, 1360), sf::Color::Red),
        sf::Vertex(sf::Vector2f(1360, 1),sf::Color::Red),
    };
    
    window.draw(right,2,sf::Lines);
    
    sf::Vertex left[] =
    {
        sf::Vertex(sf::Vector2f(1,1), sf::Color::Red),
        sf::Vertex(sf::Vector2f(1, 1360),sf::Color::Red),
    };
    
    window.draw(left,2,sf::Lines);
    
    for (int x=0; x <17; x++) {
        
        sf::Vertex line1[] =
        {
            sf::Vertex(sf::Vector2f(1, x*85), sf::Color::Color(255,255,0,50)),
            sf::Vertex(sf::Vector2f(1360, x*85),sf::Color::Color(255,255,0,50)),
        };
        
        window.draw(line1,2,sf::Lines);
        
    }
    
    for (int x=0; x <17; x++) {
        
        sf::Vertex line1[] =
        {
            sf::Vertex(sf::Vector2f(x*85,1),sf::Color::Color(255,255,0,50)),
            sf::Vertex(sf::Vector2f(x*85,1360),sf::Color::Color(255,255,0,50)),
        };
        
        window.draw(line1,2,sf::Lines);
        
    }

    
    
}







void VirtualMaze::drawAll(){
    
    window.clear();
    
    drawBackground();
    
    drawMaze();
    
    
    
}










void VirtualMaze::run(){
    
  
    
    while (window.isOpen()) {
        
        
       
        
        while (window.pollEvent(event)) {
            
            
            
            switch (event.type) {
                    
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::MouseButtonReleased:
                    
                    
                    wallToggled(event.mouseButton.x, event.mouseButton.y);
                    
                    drawAll();
                    
                    window.display();
                    
                    
                    break;
                    
                case sf::Event::KeyPressed :
                    
                    if (event.key.code == sf::Keyboard::A) {
                        
                        
                        
                        Node a(5,5);
                        Node b(2,2);
                        Node c(5,1);
                        Node d(2,16);
                        
                        
                        Path path;
                        
                        path.add(c);
                        path.add(a);
                        path.add(b);
                        path.add(d);
                        
                        drawPath(path);
                        
                        drawMaze();
                        
                        window.display();
                        
                    } else if (event.key.code == sf::Keyboard::B){
                        
                        Path temp = maze.findPath(Node(10,5), Node(1,1));
                        
                        drawAll();
                        
                        
                         std::cout << "******************" << std::endl;
                        
                        
                        while (!temp.empty()) {
                            
                             std::cout << "******************" << std::endl;
                            std::cout << temp.nextNode().returnString() << std::endl;
                        }
                        
                        drawPath(temp);
                        
                        window.display();
                        
                    } else if (event.key.code == sf::Keyboard::G){
                        
                        generateMaze();
                        
                        drawAll();
                        
                        window.display();
                        
                    }
                    
                    
                    
                    
                    break;
                    
                default:
                    break;
            }
            
        }
        
    }
    
    
}









void VirtualMaze::drawLine(const Node& from, const Node& to){
    
    
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(from.x(), from.y()), sf::Color::Green),
        sf::Vertex(sf::Vector2f(to.x(), to.y()),sf::Color::Green),
    };
    
    window.draw(line,2,sf::Lines);
    
}










Node VirtualMaze::getCenter(const Node& node) {
    
    
    Node temp = toScreen(node);
    
    return Node(temp.x()-(cellWidth/2),temp.y() + (cellWidth/2));
    
    
    
}








void VirtualMaze::drawPath(Path path){
    
        drawLine(getCenter(path.start()), getCenter(path.nextNode()));
    
    while (!path.empty()) {
        
        
        drawLine(getCenter(path.start()), getCenter(path.nextNode()));
        
    }
    
}
