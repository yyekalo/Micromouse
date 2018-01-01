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
#include <fstream>
#include <string.h>

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
#define resolution 20 // this determines the speed of the simulation


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
    
    std::vector<Direction> missingNeigbour(const Node& location, Maze maze);
    
    Node getCenter(const Node& node);
    
    void deletePath(Path path);
    
    bool isWall(const Node& direction, Direction dir );
    
    //To be removed implmented in the Mouse class
    Node followUntilbroken(Maze& maze, Path path);
    
    void VirtualBot();
    
    void drawNode(Node node);
    
    void clear();
    
    void display();
    
    void dump();
    
    void run();
    
    //Drawing functions
    
    void drawWall(const Node& location, Direction side, sf::Color color = sf::Color::Red);
    
    void drawPath(Path path,sf::Color color = sf::Color::Green);
    
    void drawPath(Node from = Node(1,1) , Node to=Node(8,8), bool diagonal=true, sf::Color color=sf::Color::Green);
    
    void drawMaze(sf::Color color = sf::Color::Red);
    
    void drawMaze(Maze maze, sf::Color color=sf::Color::Red);
    
    void drawVirtual();
    
    void drawAll();
    
    void drawBackground();
    
    
    //TODO improve this code
    void animate(Node from, Node to);
    
    void drawNode(Point location, Direction dir,sf::Color color=sf::Color::Green);
    
    
    
    //Saved math handlers
    void loadMaze();
    
    void saveMaze();
    
    
    
    
    sf::RenderWindow window;
    
private:
    
    
    void drawLine(const Node& from, const Node& to, sf::Color color);
    
    sf::Event event;
    
    Path _path;
    
    Path _temp;
    
    Maze maze;
    
    Maze _internalMaze;
    
    bool escapeRun = true;
    
    Maze botMaze;
    
    Path alreadyTravledPath;
    
    Node start;
    
    Node end;
    
    std::string directory;
};

#endif /* VirtualMaze_hpp */
