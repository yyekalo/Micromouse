//
//  main.cpp
//  teensyMicromouse
//
//  Created by Yikealo Abraha  on 4/13/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;


int main(){
    
   
    clock_t t = clock();
    
   
    
    for(int x=0;x<19;++x){
        
        std::cout << "----" ;;
        
    }
    cout<<endl;
    
    for(int m=0;m<16;++m){
        
 
    for(int x=0;x<16;++x){
    
        std::cout << "|    " ;
        
    }
    for(int x=0;x<19;++x){
        
        std::cout << "----" ;;
        
    }
        cout <<endl;
        
        
    }
  
    
    cout<<clock()-t<<endl;
    
    return 0;
}
