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


class VirtualMaze{
    
public:
    
    VirtualMaze();
    
    ~VirtualMaze();
    
    nPair getPair(int x, int y);
    
    void wallToggled(int x, int y);
    
    void randomRemoveNeigbour(const Node& loc);
    
    void generateMaze();
    
    Node toScreen(const Node& location);
    
    std::vector<Direction> missingNeigbour(const Node& location);
    
    void drawWall(const Node& location, Direction side);
    
    void drawMaze();
    
    void run();
    
    void drawLine(const Node& from, const Node& to);
    
    Node getCenter(const Node& node);
    
    void drawPath(Path path);
    
    
private:
    
    void drawAll();
    
    void drawBackground();
    
    sf::RenderWindow window;
    
    sf::Event event;
    
    Maze maze;
    
};

#endif /* VirtualMaze_hpp */
