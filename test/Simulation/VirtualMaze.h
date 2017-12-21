//
//  VirtualMaze.hpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 5/5/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef VirtualMaze_hpp
#define VirtualMaze_hpp

#include <stdio.h>
#include <utility>
#include <iostream>

//my classes
#include "Maze.h"
#include "Vector.h"
#include "Path.h"


//grpahics
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

#include <unistd.h>

//neigbour pair order goes Top/Bootom or Right/left for
typedef std::pair<Node, Node> nPair;

#define cellWidth 85
#define cellWallThickness 2


class VirtualMaze{
    
public:
    
    VirtualMaze();
    
    ~VirtualMaze();
    
    Node getNode(int x, int y);
    
    nPair getPair(int x, int y);
    
    void wallToggled(int x, int y);
    
    void randomRemoveNeigbour(const Node& loc);
    
    void generateMaze();
    
    Node toScreen(const Node& location);
    
    Node getCenter(const Node& node);
    
    void deletePath(Path path);
    
    bool isWall(const Node& direction, Direction dir );
    
    void drawNode(Node node, Direction dir = N);
    
    void drawNode2(Node node, Direction dir = N);
    
    void clear();
    
    void display();
    
    void dump();
    
    void run();
    
    //Drawing functions
    
    void drawWall(const Node& location, Direction side, sf::Color color = sf::Color::Red);
    
    void drawPath(Path path,sf::Color color = sf::Color::Green);
    
    void drawMaze(sf::Color color = sf::Color::Red);
    
    void drawMaze(Maze maze, sf::Color color=sf::Color::Red);
    
    void drawAll();
    
    void drawBackground();

    
    
   

    
   
    
    

    
    
    
private:
    
    
    void drawLine(const Node& from, const Node& to, sf::Color color);

    sf::RenderWindow window;
    
    sf::Event event;
    
    Path _path;
    
    Path _temp;
    
    Maze maze;
    
    bool escapeRun = true;
    
    Node start;
    
    Node end;
    
};

#endif /* VirtualMaze_hpp */

