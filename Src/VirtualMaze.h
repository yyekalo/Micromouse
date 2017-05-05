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
#include "Maze.h"

//grpahics
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

//neigbour pair order goes Top/Bootom or Right/left for
typedef std::pair<Node, Node> nPair;


class VirtualMaze{
    
    public:
    
    VirtualMaze();
    
    ~VirtualMaze();
    
    nPair getPair(int x, int y);
    
    
    
    void run();
    
    
    
    
    
    
    
    
    
    
    
    
//private:
    
    sf::RenderWindow window;
    
    sf::Event event;
    
    
    Maze maze;
    
};

#endif /* VirtualMaze_hpp */
