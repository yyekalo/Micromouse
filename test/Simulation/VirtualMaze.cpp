//
//  VirtualMaze.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/5/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include "VirtualMaze.h"


class CellDrawable : public sf::Transformable, public sf::Drawable {
    
public:
    CellDrawable(const Node& location, std::vector<Direction> missingNeighbour, sf::Color color = sf::Color::Red){
        
        _location = location;
        
        _missing = missingNeighbour;
        
        _color = color;
        
    }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        
        sf::RectangleShape cell(sf::Vector2f(cellWidth , cellWidth));
        
        cell.setFillColor(sf::Color::Black);
        
        cell.setOutlineThickness(2);
        
        cell.setOutlineColor(sf::Color::Color(255,255,0,50));
        
        cell.setPosition(sf::Vector2f((_location.x()-1)*cellWidth,(17-_location.y())*cellWidth));
        
        target.draw(cell);
        
        sf::RectangleShape wall(sf::Vector2f(1 , 1));
        
        wall.setFillColor(color);
        
        
        
        
            
            for(auto dir : _missing){
                
                switch (dir) {
                    case N:
                        
                        wall.setSize(sf::Vector2f(cellWidth,1));
                        
                        wall.setPosition(sf::Vector2f((_location.x()-1)*cellWidth,(17-_location.y())*cellWidth));
                        
                        target.draw(wall);
                        
                                                
                        
                        break;
                        
                    case E:
                        
                        wall.setSize(sf::Vector2f(1, cellWidth));
                        
                        wall.setPosition(sf::Vector2f((_location.x()-1)*cellWidth,(17-_location.y())*cellWidth));
                        
                        target.draw(wall);
                        
                        break;
                        
                    case S:
                        
                        wall.setSize(sf::Vector2f(cellWidth,1));
                        
                        wall.setPosition(sf::Vector2f((_location.x()-1)*cellWidth,(17-_location.y())*cellWidth));
                        
                        wall.move(0, cellWidth);
                        
                        target.draw(wall);
                        
                        
                       
                        
                        break;
                        
                    case W:
                        
                        wall.setSize(sf::Vector2f(1, cellWidth));
                        
                        wall.setPosition(sf::Vector2f((_location.x()-1)*cellWidth,(17-_location.y())*cellWidth));
                        
                        wall.move(cellWidth, 0);
                        
                        target.draw(wall);
                        
                        break;
                        
                    default:
                        break;
                }
            }
       
        
    }
    
private:
    
    Node                     _location;
    
    std::vector<Direction>   _missing;
    
    sf::Color                _color;
    
};











VirtualMaze::VirtualMaze(){
    
    maze = Maze();
    
    dynamic = false;
    
    start = Node(1,1);
    
    end = Node(8,8);
    
    window.create(sf::VideoMode(1400,1400),"my home");
    
    drawBackground();
    
    window.display();
    
    window.setVerticalSyncEnabled(true);
    
    
    
    //run();
}







VirtualMaze::~VirtualMaze(){
    
    window.close();
}






//gets screen coordinate return at that location.
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













//TODO:  remove this option
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
        
        
        
        randomRemoveNeigbour(nodes.first);
        
        
    }
    
    
    
    
    
}









Node VirtualMaze::toScreen(const Node& location){
    
    return Node(location.x()*cellWidth,(16-location.y())*cellWidth);
    
    
}











std::vector<Direction> VirtualMaze::missingNeigbour(const Node& location, Maze inmaze){
    
    std::vector<Direction>  temp;
    Direction side;
    
    
    
    for(auto neigbour : inmaze.getNeighbour(location)){
        
        if(!inmaze.areNeighbours(location, neigbour)){
            
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














void VirtualMaze::drawMaze(sf::Color color){
    
    drawBackground();
   
    for(auto pair : maze.getMaze()){
        
        for(auto dir : missingNeigbour(pair.first,maze)){
            
            drawWall(pair.first, dir,color);
        }

        
    }
    
    display();
    
    dump();
    
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







<<<<<<< HEAD:test/Simulation/VirtualMaze.cpp

void VirtualMaze::animate(Node from, Node to){

    int m=6;
    for(int x=0; x<cellWidth/m ; x++){
        
        clear();
       
        switch (from.whichSide(to)) {
            case N:
                
                drawNode2(Node(getCenter(from).x(),getCenter(from).y()-(x*m)),from.whichSide(to));
                
                break;
                
            case S:
                
                drawNode2(Node(getCenter(from).x(),getCenter(from).y()+(x*m)),from.whichSide(to));
                
                break;
                
            case E:
                
                drawNode2(Node(getCenter(from).x()+(x*m),getCenter(from).y()),from.whichSide(to));
                
                
                break;
            case W:
                
                drawNode2(Node(getCenter(from).x()-(x*m),getCenter(from).y()),from.whichSide(to));
                
                break;
            default:
                break;
        }
        
        
        
        
        
        
        
        
        
        drawMaze(internalMaze);
    
        //usleep(10000);
        
        
    }
    
    
    
    
}






=======
>>>>>>> parent of e420c36... fixed the polling problem.:Src/VirtualMaze.cpp
void VirtualMaze::drawAll(){
    
    window.clear();
    
    drawBackground();
    
    drawMaze();
    
    drawPath(_path,sf::Color::White);
    
    window.display();
    
}










void VirtualMaze::run(){
    
  
    
    while (window.isOpen() && escapeRun) {
        
        
       
        
        while (window.pollEvent(event)&& escapeRun) {
            
            
            
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
                     
                        _path = maze.findPath(start, end);
                        
                        drawAll();
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::C){
                        
                        
                        maze.resetMaze();
                        
                        _path = Path(Node(0,0));
                        
                        alreadyTravledPath = Path(Node(0,0));
                        
                        drawAll();
                        
                        
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::D){
                        
                        dynamic = !dynamic;
                        
                        _path = maze.findPath(start, end);
                        
                        drawAll();
                        
                    }
                    
                    
                    
                    
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::R){
                        
                        
                        escapeRun = false;
                        
                    }
                    
                    
                    if (event.key.code == sf::Keyboard::V){
                        
                        
                        VirtualBot();
                        
                    }

                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::G){
                        
                        
                        generateMaze();
                        
                        drawAll();
                        
                    }
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::E){
                        
                        
                        end =  getNode(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                       
                       
                    }
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::S){
                        
                        
                        start = getNode(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                       
                        
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
    
    drawBackground();
    
    
    for(auto pair : inmaze.getMaze()){
        
        
        
        for(auto dir : missingNeigbour(pair.first,inmaze)){
            
            drawWall(pair.first, dir, color);
            
        
            
            
        }
        
        
    }

    display();
    
    dump();
    
}



















Node VirtualMaze::followUntilbroken(Maze& maze, Path path){
    
    
    Node currentNode = path.start();
    
    while (!path.empty()) {
        
       
        if (isWall(currentNode, N)) {
            
            maze.removeNeighbour(currentNode, N);
            
            drawWall(currentNode, N);

          
            
        }
        
        if (isWall(currentNode, NE)) {
            
            maze.removeNeighbour(currentNode, NE);
            
           
            
            
        }
        
        if (isWall(currentNode, E)) {
            
            maze.removeNeighbour(currentNode, E);
            
            drawWall(currentNode, E);
            
           
            
        }
        
        if (isWall(currentNode, SE)) {
            
            maze.removeNeighbour(currentNode, SE);
          
            
            
        }
        
        if (isWall(currentNode, S)) {
            
            maze.removeNeighbour(currentNode, S);
            
          
            
        }
        
        if (isWall(currentNode, W)) {
            
            maze.removeNeighbour(currentNode, W);
            
            drawWall(currentNode, W);
            
            
        }
        
        if (isWall(currentNode, SE)) {
            
            maze.removeNeighbour(currentNode, SW);
            
            
            
        }
        
        if (isWall(currentNode, NW)) {
            
            maze.removeNeighbour(currentNode, NW);
            
            
        }
        
        
         botMaze = maze;
        
        
        drawVirtual();
        
        
        maze.print(currentNode);
        
        
        if (isWall(currentNode, currentNode.whichSide(path.peekNode()))) {
            
            
            return currentNode;
            
        }
        
       
        
        currentNode = path.nextNode();
    }
    
    
    
    
    return currentNode;
    
}













void VirtualMaze::VirtualBot(){
    
    Maze botMaze;
    
    Node center = end;
    
    Node original = start;
    
    Node currentNode = start;
    
    _temp = maze.findPath(start, end);
    
    while (currentNode != center ) {
        
    
    
<<<<<<< HEAD:test/Simulation/VirtualMaze.cpp
    
    drawMaze(internalMaze);
=======
   
        
      _path =  botMaze.findPath(currentNode, center,false);
>>>>>>> parent of e420c36... fixed the polling problem.:Src/VirtualMaze.cpp

       
       
        if (_path.start() == Node(0,0)) {
            
            std::cout <<"No path to find"<< std::endl;
            return ;
        }
        
        
        
      currentNode =   followUntilbroken(botMaze, _path);
        
        alreadyTravledPath = maze.findPath(original, currentNode,false);

        
        usleep(500000);
        
    }
    
    while (currentNode != start ) {
        
        
        
        
        
        _path =  botMaze.findPath(currentNode, start,false);
        
        
        
        if (_path.start() == Node(0,0)) {
            
            std::cout <<"No path to find"<< std::endl;
            return ;
        }
        
        
        
        currentNode =   followUntilbroken(botMaze, _path);
        
        alreadyTravledPath = maze.findPath(center, currentNode,false);
        
        
        usleep(500000);
        
    }
    

    _path = botMaze.findPath(start, end);
    
    drawVirtual();
    
    std::cout <<"Done found the path"<< std::endl;
    
}











<<<<<<< HEAD:test/Simulation/VirtualMaze.cpp




void VirtualMaze::drawNode2(Node pos, Direction dir){
    
    sf::CircleShape temp(30,3);
    
    temp.setOrigin(30, 30);
    
    temp.setRotation(float(45.0* dir));
    
    temp.setPosition(pos.x(), pos.y());
    
    temp.setFillColor(sf::Color::Green);
    
    window.draw(temp);
    
    drawMaze(internalMaze);
    
=======
void VirtualMaze::drawNode(Node node){
>>>>>>> parent of e420c36... fixed the polling problem.:Src/VirtualMaze.cpp
    
    sf::CircleShape temp(50);

    

}










void VirtualMaze::clear(){
    
    window.clear();
    
    drawBackground();
    
}









void VirtualMaze::display(){
    
    window.display();
    
}








void VirtualMaze::dump(){
    
    if (window.waitEvent(event)) {
        
       
    }
}







void VirtualMaze::drawVirtual(){
    
    window.clear();
    
    drawBackground();
    
    drawPath(_temp,sf::Color::Cyan);
    
    drawMaze(sf::Color::Color(0,255,255,50));
    
    drawMaze(botMaze,sf::Color::Red);
    
    drawPath(alreadyTravledPath,sf::Color::Green);
    
    drawPath(_path,sf::Color::White);
    
    window.display();
    
    
}









