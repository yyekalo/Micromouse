//
//  main.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 4/22/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <unistd.h> //for sleep time







//Graphic include
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

using namespace std;

//My own includes
#include "Vector.h"
#include "Maze.h"
#include "VirtualMaze.h"
#include "Mouse.h"

#define center  Node(8,8)
#define Start   Node(1,1)




/*
 
 sf::CircleShape temp(30,3);
 
 temp.setOrigin(30, 30);
 
 temp.setRotation(float(45.0* dir));
 
 temp.setPosition(pos.x(), pos.y());
 
 temp.setFillColor(sf::Color::Green);
 
 window.draw(temp);
 
 display();
 
 */




int main(){
    
    
    Mouse Mouse;

    VirtualMaze temp;
    
    Maze t;
    
    t.removeNeighbour(Node(1,1), N);
    t.removeNeighbour(Node(1,2), N);
    t.removeNeighbour(Node(1,3), N);
    t.removeNeighbour(Node(1,4), N);
    temp.drawMaze(t);
    
    
   
   
    
   temp.animate(Node(1,1), Node(1,2));
   temp.animate(Node(1,2), Node(2,2));
   temp.animate(Node(2,2), Node(2,1));
  temp .animate(Node(1,1), Node(1,2));
    
    
    for (int x =1; x<16; x++ ) {
        
        for (int y =1 ; y <16; y++) {
            
            temp.animate(Node(x,y), Node(x,y+1));
            
        }
        
    }
    
    
    while (true) {
        
    }
    
        return 0;
}

/*
 
 
 sf::Vertex wall[] =
 {
 sf::Vertex(sf::Vector2f(400,400 ),sf::Color::White),
 sf::Vertex(sf::Vector2f(400 ,450 ),sf::Color::White),
 };
 
 
 
 
 
 
 sf::RectangleShape temp(sf::Vector2f(2, 100));
 temp.setPosition(400, 400);
 temp.setOutlineColor(sf::Color::Red);
 //temp.setRotation(90);
 //temp.setOutlineThickness(4);
 temp.setFillColor(sf::Color::Red);
 
 sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
 
 // run the program as long as the window is open
 while (window.isOpen())
 {
 // check all the window's events that were triggered since the last iteration of the loop
 sf::Event event;
 while (window.pollEvent(event))
 {
 // "close requested" event: we close the window
 if (event.type == sf::Event::Closed)
 window.close();
 }
 
 // clear the window with black color
 window.clear(sf::Color::Black);
 
 
 
 window.draw(wall, 2, sf::Lines);
 
 window.draw(temp);
 // end the current frame
 window.display();
 
 }
 
 */

/*
 sf::RectangleShape temp(sf::Vector2f(120, 50));
 temp.setPosition(loc.x(), loc.y());
 temp.setOutlineColor(sf::Color::Red);
 temp.setOutlineThickness(4);
 temp.setFillColor(sf::Color::Blue);
 
 sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
 
 // run the program as long as the window is open
 while (window.isOpen())
 {
 // check all the window's events that were triggered since the last iteration of the loop
 sf::Event event;
 while (window.pollEvent(event))
 {
 // "close requested" event: we close the window
 if (event.type == sf::Event::Closed)
 window.close();
 }
 
 // clear the window with black color
 window.clear(sf::Color::Black);
 
 window.draw(temp);
 
 // end the current frame
 window.display();
 
 
 
 
 
 }
 */

