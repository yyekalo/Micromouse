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
    
    dynamic = false;
    
    virtualbot = false;
    
    window.create(sf::VideoMode(1400,1400),"my home");
    
    drawBackground();
    
    window.display();
    
    run();
}







VirtualMaze::~VirtualMaze(){
    
    window.close();
}

Node VirtualMaze::getNode(int x, int y){
    
    int tempx = (x/cellWidth) + 1;
    int tempy = 16 - (y/cellWidth);
    
    return Node(tempx,tempy);
    
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








void VirtualMaze::drawWall(const Node& location, Direction side,sf::Color color){
    
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
        sf::Vertex(sf::Vector2f(x1,y1 ),color),
        sf::Vertex(sf::Vector2f(x2,y2 ),color),
    };
    
    
    window.draw(wall, 2, sf::Lines);
    
    
    
}














void VirtualMaze::drawMaze(){
    
   
    for(auto pair : maze.getMaze()){
        
        for(auto dir : missingNeigbour(pair.first)){
            
            drawWall(pair.first, dir,sf::Color::Magenta);
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
    
    if (virtualbot) {
        
        drawMaze(botMaze);
        drawPath(alreadyTravledPath,sf::Color::Green);
        
    }
    
    drawPath(_path,sf::Color::White);
    
    window.display();
    
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
                    
                    if (dynamic) {
                        
                    
                    _path = maze.findPath(Node(1,1), Node(8,8));                    
                                        }
                    drawAll();

                    break;
                    
                    
                    
                    
                case sf::Event::KeyPressed :
                    
                    if (event.key.code == sf::Keyboard::A) {
                        
                        drawAll();
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::B){
                     
                        _path = maze.findPath(Node(1,1), Node(8,8));
                        
                        
                        drawAll();
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::C){
                        
                        
                        maze.resetMaze();
                        
                        _path = Path(Node(0,0));
                        
                        drawAll();
                      
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::C){
                        
                        
                        maze.resetMaze();
                        
                        _path = Path(Node(0,0));
                        
                        alreadyTravledPath = Path(Node(0,0));
                        
                        drawAll();
                        
                        
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::S){
                        
                        
                        drawWall(Node(1,1), E);
                        
                        window.display();
                        
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::V){
                        
                        virtualbot = true;
                        
                        VirtualBot();
                        
                    }

                    
                    if (event.key.code == sf::Keyboard::G){
                        
                        
                        generateMaze();
                        
                        drawAll();
                        
                    }
                    
                    break;
                    
                default:
                    break;
            }
            
        }
        
    }
    
    
}












void VirtualMaze::drawLine(const Node& from, const Node& to, sf::Color color){
    
    
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(from.x(), from.y()), color),
        sf::Vertex(sf::Vector2f(to.x(), to.y()),color),
    };
    
    window.draw(line,2,sf::Lines);
    
}










Node VirtualMaze::getCenter(const Node& node) {
    
    
    Node temp = toScreen(node);
    
    return Node(temp.x()-(cellWidth/2),temp.y() + (cellWidth/2));
    
    
    
}








void VirtualMaze::drawPath(Path path,sf::Color color){
    
       while (!path.empty()) {
        
        
        drawLine(getCenter(path.start()), getCenter(path.nextNode()),color);
        
    }
    
   

}











void VirtualMaze::deletePath(Path path){
    
    drawPath(path,sf::Color::Black);
    
    
}










bool VirtualMaze::isWall(const Node& node, Direction dir ){
    
    return !maze.isNeigbour(node, dir);
    
}









void VirtualMaze::drawMaze(Maze inmaze, sf::Color color){
    
    
    for(auto pair : inmaze.getMaze()){
        
        for(auto dir : missingNeigbour(pair.first)){
            
            drawWall(pair.first, dir, color);
        }
        
        
    }

    
    
}









Node VirtualMaze::followUntilbroken(Maze& maze, Path path){
    
    
    Node currentNode = path.start();
    
    while (!path.empty()) {
        
        std::cout <<"**************************************************" <<  std::endl;
        std::cout <<"*********  at "<<currentNode.returnString() << "*********************" <<  std::endl;
                
        if (isWall(currentNode, N)) {
            
            maze.removeNeighbour(currentNode, N);
            
            drawWall(currentNode, N);

            std::cout <<"discovered N wall" <<  std::endl;
            
        }
        
        if (isWall(currentNode, NE)) {
            
            maze.removeNeighbour(currentNode, NE);
            
           
            std::cout <<"discovered NE wall" <<  std::endl;
            
        }
        
        if (isWall(currentNode, E)) {
            
            maze.removeNeighbour(currentNode, E);
            
            drawWall(currentNode, E);
            
            std::cout <<"discovered E wall" <<  std::endl;
            
        }
        
        if (isWall(currentNode, SE)) {
            
            maze.removeNeighbour(currentNode, SE);
          
            std::cout <<"discovered SE wall" <<  std::endl;
            
        }
        
        
        if (isWall(currentNode, W)) {
            
            maze.removeNeighbour(currentNode, W);
            
            drawWall(currentNode, W);
            
            std::cout <<"discovered W wall" <<  std::endl;
        
        }
        
        if (isWall(currentNode, SE)) {
            
            maze.removeNeighbour(currentNode, SW);
            
            
            std::cout <<"discovered SW wall" <<  std::endl;
            
        }
        
        if (isWall(currentNode, NW)) {
            
            maze.removeNeighbour(currentNode, NW);
            
            std::cout <<"discovered NW wall" <<  std::endl;
            
        }
        
        
         botMaze = maze;
        
        
        drawAll();
        
        
//        maze.print(Node(1,1));
//        std::cout <<"###############" <<  std::endl;

        
        //std::cout <<"next node" << path.peekNode().returnString() <<  std::endl;
        
        maze.print(currentNode);
        
        std::cout <<"###############" <<  std::endl;
        
        if (isWall(currentNode, currentNode.whichSide(path.peekNode()))) {
            
            std::cout <<"over and returned " <<  currentNode.returnString() << std::endl;
            
            return currentNode;
            
        }
        
        std::cout <<"###############" <<  std::endl;

        
        currentNode = path.nextNode();
    }
    
    
    
    
    return currentNode;
    
}













void VirtualMaze::VirtualBot(){
    
    Maze botMaze;
    
    Node center = Node(8,8);
    
    Node original = Node(1,1);
    
    Node currentNode = Node(1,1);
    
    Path imagPath;
    
    while (currentNode != center) {
        
    
    
    imagPath = botMaze.findPath(currentNode, center);

        _path = imagPath;
        
        imagPath.print();
        
        
        
      currentNode =   followUntilbroken(botMaze, imagPath);
        
        alreadyTravledPath = botMaze.findPath(original, currentNode,false);

        
        usleep(1100000);
        
    }
    
    
    
    std::cout <<"Done found the path"<< std::endl;
    
}











void VirtualMaze::drawNode(Node node){
    
    sf::CircleShape temp(50);

    

}








