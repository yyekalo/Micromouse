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







//Graphic include
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Time.hpp>

using namespace std;

//My own includes
#include "Vector.h"
#include "Maze.h"
#include "VirtualMaze.h"

void print(Maze maze, Node node){
    
    for(auto temp :maze.getStoredNeighbour(node))
        
        std::cout << temp.returnString()  << std::endl;
}



//unordered_map<Node, float, NodeHasher> temp1;
//
//temp1[Node(1,1)] = 19108.3;
//
//
//std::cout <<temp1[Node(1,1)] << endl;
//
//temp1.clear();
//
//std::cout <<temp1.count(Node(1,1)) << endl;
//temp1[Node(1,1)] = 9930;
//std::cout <<temp1.count(Node(1,1)) << endl;
//





int main(){
    
  
   
    VirtualMaze mm;
    
    
    
    return 0;
}



/*
 
 sf::RenderWindow window(sf::VideoMode(1600,1600),"my home");
 
 sf::Event event;
 
 //    sf::Vertex line1[] =
 //    {
 //        sf::Vertex(sf::Vector2f(1, 1),sf::Color::Red),
 //        sf::Vertex(sf::Vector2f(1600, 1),sf::Color::Red),
 //    };
 
 sf::Vertex line2[] =
 {
 sf::Vertex(sf::Vector2f(1, 100),sf::Color::Red),
 sf::Vertex(sf::Vector2f(1600, 100),sf::Color::Red),
 };
 sf::Vertex line3[] =
 {
 sf::Vertex(sf::Vector2f(10, 10),sf::Color::Red),
 sf::Vertex(sf::Vector2f(0, 10),sf::Color::Red),
 };
 sf::Vertex line4[] =
 {
 sf::Vertex(sf::Vector2f(0, 10),sf::Color::Red),
 sf::Vertex(sf::Vector2f(0, 0),sf::Color::Red),
 };
 
 
 
 while (window.isOpen()) {
 
 while (window.pollEvent(event)) {
 
 switch (event.type) {
 case sf::Event::Closed:
 window.close();
 break;
 
 case sf::Event::MouseButtonReleased:
 std::cout << "button released "<<  event.mouseButton.x << " , " << event.mouseButton.y <<  std::endl;
 break;
 case sf::Event::MouseMoved:
 std::cout << "button released "<<  event.mouseMove.x << " , " << event.mouseMove.y <<  std::endl;
 break;
 case sf::Event::MouseWheelScrolled:
 if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
 std::cout << "wheel type: vertical" << std::endl;
 else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
 std::cout << "wheel type: horizontal" << std::endl;
 else
 std::cout << "wheel type: unknown" << std::endl;
 std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
 std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
 std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
 break;
 
 
 
 default:
 break;
 }
 
 window.clear();
 
 
 for (int x=1; x <17; x++) {
 
 sf::Vertex line1[] =
 {
 sf::Vertex(sf::Vector2f(1, x*100),sf::Color::Red),
 sf::Vertex(sf::Vector2f(1600, x*100),sf::Color::Red),
 };
 
 window.draw(line1,2,sf::Lines);
 
 }
 
 for (int x=1; x <17; x++) {
 
 sf::Vertex line1[] =
 {
 sf::Vertex(sf::Vector2f(x*100,1),sf::Color::Red),
 sf::Vertex(sf::Vector2f(x*100,1600),sf::Color::Red),
 };
 
 window.draw(line1,2,sf::Lines);
 
 }
 // window.draw(line1,2,sf::Lines);
 window.draw(line2,2,sf::Lines);
 //            window.draw(line3,2,sf::Lines);
 //            window.draw(line4,2,sf::Lines);
 //
 
 
 window.display();
 }
 
 }
 
 
 
 */
