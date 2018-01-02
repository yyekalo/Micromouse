//
//  Vector.cpp
//  test
//
//  Created by Yikealo Abraha on 1/1/18.
//  Copyright © 2018 Yikealo Abraha. All rights reserved.
//

#include <stdio.h>
#include "Vector.h"




/* Credit for the following two functions goes out to
 
 Patrick Johnmeyer from
 https://stackoverflow.com/questions/2571456/operators-overloading-for-enums
 */
Direction& operator++(Direction& orig){
    

    if (orig==NW) {
        
        orig=N;
        
        return orig;
    }

    orig =  static_cast<Direction>(orig+1);

    return orig;

}




Direction operator++(Direction& orig, int)
{
    Direction rVal = orig;
    ++orig;
    return rVal;
}





int operator-(Direction first, Direction second){
    
    
    return abs(static_cast<int>(first)- static_cast<int>(second)) > 4 ? 8 -abs(static_cast<int>(first)- static_cast<int>(second)): abs(static_cast<int>(first)- static_cast<int>(second));
    
    
    
    

}
