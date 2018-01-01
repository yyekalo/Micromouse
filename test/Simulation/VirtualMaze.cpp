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
    
    escapeRun = true;
    
    start = Node(1,1);
    
    end = Node(8,8);
    
    window.create(sf::VideoMode(1400,1400),"my home");
    
    drawBackground();
    
    window.display();
    
    directory = "/Users/yikealo/Documents/github/Micromouse/Resource/";
    
    
    
    //run();
}







VirtualMaze::~VirtualMaze(){
    
    window.close();
}






//get screen coordinate return at that location.
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
    
    
    for(auto pair : maze.getMaze()){
        
        for(auto dir : missingNeigbour(pair.first,maze)){
            
            drawWall(pair.first, dir,color);
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
    
    sf::RectangleShape centers(sf::Vector2f(2*cellWidth,2*cellWidth));
    
    centers.setOrigin(cellWidth, cellWidth);
    centers.setPosition(8*cellWidth, 8*cellWidth);
    centers.setFillColor(sf::Color::Color(0,0,255,100));
    
    window.draw(centers);
    
    
}








void VirtualMaze::animate(Node from, Node to){
    

    
   
    
    Point mouse = getCenter(from);
    
    for (int x=0; x < cellWidth/resolution; x++) {
        
       mouse = getCenter(from);
        
        switch (from.whichSide(to)) {
                
            case N:
                
                mouse.y(mouse.y()-(resolution * x));
                
                break;
                
            case E:
                
                mouse.x(mouse.x()+(resolution * x));
                
                break;
                
            case S:
                
                mouse.y(mouse.y()+(resolution * x));
                
                break;
                
            case W:
                
                mouse.x(mouse.x()-(resolution * x));
                
                break;
                
            default:
                break;
        }
    
        
        drawNode(mouse, from.whichSide(to), sf::Color::Green);
    
        usleep(10000);
        
        window.display();
    
        drawNode(mouse, from.whichSide(to),sf::Color::Black);
        window.display();
        
        if (x==59) {
            
            drawWall(from, from.whichSide(to),sf::Color::Color(255,255,0,50));
        }
       
        //usleep(10000);
        
   }
    
   
    //window.clear();
    
    //drawMaze(_internalMaze);
    
    //drawNode(Point(getCenter(to).x(),getCenter(to).y()), from.whichSide(to),sf::Color::Green);
    
   
   
}





void VirtualMaze::drawAll(){
    
    window.clear();
    
    drawBackground();
    
    drawMaze();
    
    drawPath(_path,sf::Color::White);
    
    window.display();
    
}










void VirtualMaze::run(){
    
    
    
    while (window.isOpen() && escapeRun) {
        
        
        
        
        while (window.pollEvent(event)) {
            
            
            
            switch (event.type) {
                    
                    
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                    
                    
                case sf::Event::MouseButtonReleased:
                    
                    wallToggled(event.mouseButton.x, event.mouseButton.y);
                    
                    
                    drawAll();
                    
                    break;
                    
                    
                    
                    
                case sf::Event::KeyPressed :
                    
                    if (event.key.code == sf::Keyboard::A) {
                        
                        drawAll();
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::B){
                        
                        _path = maze.findPath(start, end,false);
                        
                        drawAll();
                        
                    }
                    
                    if (event.key.code == sf::Keyboard::C){
                        
                        
                        maze.resetMaze();
                        
                        _path = Path(Node(0,0));
                        
                        alreadyTravledPath = Path(Node(0,0));
                        
                        drawAll();
                        
                        
                        
                    }
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::E){
                        
                        
                        end =  getNode(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                        
                        
                    }
                    
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::G){
                        
                        
                        generateMaze();
                        
                        drawAll();
                        
                    }
                    
                    
                    
                    
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::L){
                        
                        
                        loadMaze();
                        
                    }


                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::S){
                        
                        
                        start = getNode(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                        
                        
                    }
                    
                    
                    if (event.key.code == sf::Keyboard::R){
                        
                        
                        escapeRun = false;
                        
                    }
                    
                    
                    
                    
                    
                    if (event.key.code == sf::Keyboard::Q){
                        
                        
                        saveMaze();
                        
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










void VirtualMaze::drawPath(Node from , Node to, bool diagonal, sf::Color color){
    
    drawPath(maze.findPath(from, to,diagonal),color);
    
}









void VirtualMaze::deletePath(Path path){
    
    drawPath(path,sf::Color::Black);
    
    
}










bool VirtualMaze::isWall(const Node& node, Direction dir ){
    
    return !maze.isNeigbour(node, dir);
    
}









void VirtualMaze::drawMaze(Maze inmaze, sf::Color color){
    
    _internalMaze = inmaze;
    
    drawBackground();
    
    
    for(auto pair : inmaze.getMaze()){
        
        
        
        for(auto dir : missingNeigbour(pair.first,inmaze)){
            
            drawWall(pair.first, dir, color);
            
            
            
            
        }
        
        
    }
    
    display();
    
    dump();
    
}











void VirtualMaze::drawNode(Point pos, Direction dir,sf::Color color){
    
    sf::CircleShape temp(30,3);
    
    temp.setOrigin(30, 30);
    
    temp.setRotation(float(45.0 * dir));
    
    temp.setPosition(pos.x(), pos.y());
    
    temp.setFillColor(color);
    
    window.draw(temp);
    
    display();
    
    
    
}










void VirtualMaze::clear(){
    
    window.clear();
    
    drawBackground();
    
}









void VirtualMaze::display(){
    
    window.display();
    
}








void VirtualMaze::dump(){
    
    window.pollEvent(event);
    
}










void VirtualMaze::loadMaze(){
    
    char m;
    
    maze.resetMaze();
    
    std::string name;
    
    std::cout << "Enter the name of the maze to load ";
    
    std::cin >> name;
    
    std::ifstream mazein;
    
    mazein.open (directory + name , std::ifstream::in);
    
    
    for (int y =1; y <=16; y++) {
        
        for (int x=1 ; x<=16 ; x++) {
            
          
            if(49 == mazein.get())
            {
                maze.removeNeighbour(Node(x,y), N);


            }


            if(49 == mazein.get())
            {
                 maze.removeNeighbour(Node(x,y), E);

            }
            
            
            
        }
        
    }
    
    
    
    
    mazein.close();
    
    window.clear();
    window.display();
    drawAll();
    
}






void VirtualMaze::saveMaze(){
    
    std::string name;
    
    std::cout << "Enter the name to save the maze as ";
    std::cin >> name;
    
    std::ofstream myfile;
    
    myfile.open (directory + name);
 
        
        for (int y =1; y <=16; y++) {
            
            for (int x=1 ; x<=16 ; x++) {
            
            if(!maze.isNeigbour(Node(x,y), N))
            {
                myfile << 1;
                
               
                
            }else {
                
                myfile << 0;
            }
                
            if(!maze.isNeigbour(Node(x,y), E))
            {
                    myfile << 1;
                
            }
            else
            {
                    
                    myfile << 0;
            }
            
        }
        
    }
    


     myfile.close();
    
}







