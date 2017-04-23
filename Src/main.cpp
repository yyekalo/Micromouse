//
//  main.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 4/22/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

#include "Node.h"

int main(){
    
    
    
    Location<int> temp(0,0);
    Location<int> temp2(1,1);
    temp = temp2;
    
        

    
    
    return 0;
}



/*
 sf::RenderWindow window(sf::VideoMode(1440,1440),"my home");
 
 sf::Event event;
 
 sf::Vertex line[] =
 {
 sf::Vertex(sf::Vector2f(10, 10),sf::Color::Red),
 sf::Vertex(sf::Vector2f(500, 10),sf::Color::Red),
 };
 
 sf::Vertex lne[] =
 {
 sf::Vertex(sf::Vector2f(10, 10),sf::Color::Red),
 sf::Vertex(sf::Vector2f(10, 500),sf::Color::Red),
 };
 
 
 
 while (window.isOpen()) {
 
 while (window.pollEvent(event)) {
 
 switch (event.type) {
 case sf::Event::Closed:
 window.close();
 break;
 
 case sf::Event::MouseButtonReleased:
 std::cout << "button released"<<std::endl;
 break;
 case sf::Event::MouseMoved:
 std::cout << "mouse moved"<<std::endl;
 break;
 
 
 default:
 break;
 }
 
 
 window.draw(line,2,sf::Lines);
 window.display();
 }
 
 }


*/
