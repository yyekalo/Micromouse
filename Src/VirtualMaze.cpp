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
    
//    std::cout << temp.first.returnString() << std::endl;
//    std::cout << temp.second.returnString() << std::endl;
    
    
    if( maze.areNeighbours(temp.first, temp.second)){
        
       
        maze.removeNeighbour(temp.first, temp.second);
        
        
        
    } else {
        
         
        maze.addNeighbour(temp.first, temp.second);
    }
    
    
}













Node VirtualMaze::toScreen(const Node& location){
    
    return Node(location.x()*85,(16-location.y())*85);
    
    
}









std::vector<Direction> VirtualMaze::missingNeigbour(const Node& location){
    
    std::vector<Direction>  temp;
    
    
    
    for(auto neigbour : maze.getNeighbour(location)){
        
        if(!maze.areNeighbours(location, neigbour)){
            
            temp.push_back(location.whichSide(neigbour));
            
                       
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
    
    
    for(auto pair : maze.maze){
        
        for(auto dir : missingNeigbour(pair.first)){
            
            drawWall(pair.first, dir);
        }

        
    }
    
}











void VirtualMaze::drawBackground(){
    
    
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








void VirtualMaze::run(){
    
    
    
    while (window.isOpen()) {
        
        
       
        
        while (window.pollEvent(event)) {
            
            switch (event.type) {
                    
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::MouseButtonReleased:
                    
                    //std::cout << "button released "<<  event.mouseButton.x << " , " << event.mouseButton.y <<  std::endl;
                    
                    wallToggled(event.mouseButton.x, event.mouseButton.y);
                    
                    break;
                    
                default:
                    break;
            }
            
            
            
            window.clear();
            
            drawBackground();
            
            drawMaze();
            
            
            
            
            window.display();
        }
        
    }
    
    
}
