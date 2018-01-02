////
//  main.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 4/22/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

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


using namespace std;





int main(){
    
    
    Mouse m;
    
    VirtualMaze temp;
    
    temp.run();
    
   
  
    
    
    
    
    
    return 0;
    
}







/*
 
 //Mouse m;
 
 Maze temp;
 
 Path t = temp.findPath(Node(2,2) , Node(3,3),false);
 t.add(Node(1,2));
 t.add(Node(1,1));
 
 
 t.print();
 
 Path compressedPath = t.compress();
 
 float cost =0;
 
 int ma,size = compressedPath.size();
 
 Direction lastDirection;
 
 int numberof45turns=0;
 
 
 do{
 
 size = compressedPath.size();
 
 ma = compressedPath.peek().Mag();
 
 cost +=  0.19*pow(compressedPath.peek().Mag(), 0.5);
 
 lastDirection = compressedPath.next().Dir();
 
 numberof45turns += abs(lastDirection - compressedPath.peek().Dir());
 
 }while (compressedPath.size()>1);
 
 cost +=  0.19*pow(compressedPath.peek().Mag(), 0.5);
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 */



/*
 
 
 for (int x=1; x<=16; x++) {
 
 for (int y=1; y<=16; y++) {
 
 
 
 }
 
 }
 
 
 
 */





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

