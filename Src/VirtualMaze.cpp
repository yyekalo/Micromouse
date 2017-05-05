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
    
    window.create(sf::VideoMode(1600,1600),"my home");
    
    run();
}

VirtualMaze::~VirtualMaze(){
    
    window.close();
}







//NEXT TODO implment this
//gets corrdinate in the screen adn try to find a pair of nodes that are
// adjucent to the wall clicked.
nPair VirtualMaze::getPair(int x, int y){
    
    if (x%100 < y%100) {
        
        
        
    } else {
        
    }
    
    
    return std::make_pair(Node(16-(x/100),16-(y/100)), Node());
    
    
    
    
}



void VirtualMaze::run(){
    
    int x=0,y=0,x1=0,y1=0;
    
    while (window.isOpen()) {
        
        while (window.pollEvent(event)) {
            
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                    
                case sf::Event::MouseButtonReleased:
                    std::cout << "button released "<<  event.mouseButton.x << " , " << event.mouseButton.y <<  std::endl;
                    x1 = event.mouseButton.x;
                    y1 = event.mouseButton.y;
                    
              
                    
                    
                    
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
                    
                case sf::Event::MouseButtonPressed:
                    
                    
                    
                    x = event.mouseButton.x;
                    y = event.mouseButton.y;
                    
                  
                    
                default:
                    break;
            }
            
            window.clear();
            
            sf::Vertex lin[] =
            {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Color(255,255,0,50)),
                sf::Vertex(sf::Vector2f(x1, y1),sf::Color::Color(255,255,0,50)),
            };
            
            window.draw(lin,2,sf::Lines);
            
        
            
            for (int x=1; x <17; x++) {
                
                sf::Vertex line1[] =
                {
                    sf::Vertex(sf::Vector2f(1, x*100), sf::Color::Color(255,255,0,50)),
                    sf::Vertex(sf::Vector2f(1600, x*100),sf::Color::Color(255,255,0,50)),
                };
                
                window.draw(line1,2,sf::Lines);
                
            }
            
            for (int x=1; x <17; x++) {
                
                sf::Vertex line1[] =
                {
                    sf::Vertex(sf::Vector2f(x*100,1),sf::Color::Color(255,255,0,50)),
                    sf::Vertex(sf::Vector2f(x*100,1600),sf::Color::Color(255,255,0,50)),
                };
                
                window.draw(line1,2,sf::Lines);
                
            }
            
            
            window.display();
        }
        
    }
    
    
}
