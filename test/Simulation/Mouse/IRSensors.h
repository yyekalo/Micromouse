//
//  IRSensors.hpp
//  test
//
//  Created by Yikealo Abraha on 12/30/17.
//  Copyright © 2017 Yikealo Abraha. All rights reserved.
//

#ifndef IRSensors_hpp
#define IRSensors_hpp

#include <stdio.h>


enum IR {

    
        DL,   DR,
    
    L,               R,
    
LF ,                     RF
    
    
    
};

enum Side {
    
    /*
     
     ________FF__________
     |                  |
     |                  |
     | FL           FR  |
     |                  |
     |                  |
     |_______F__________|
     |                  |
     |                  |
     | L              R |
     |                  |
     |                  |
     
     
     */
    
    FF, FL ,FR , LS , RS
    
    
    
};


class IRSensors{
    
    
public:
    
    IRSensors();
    
    float getDistance(IR sensor);
    
    void calibrate();
    
    bool isWall(Side);
    

private:
    
    float side;
    
    float diagonal;
    
    float front;

  
};










#endif /* IRSensors_hpp */
