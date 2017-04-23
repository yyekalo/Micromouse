//
//  Node.hpp
//  lkn
//
//  Created by Yikealo Abraha  on 4/19/17.
//  Copyright © 2017 Yikealo Abraha . All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include "Vector.h"
#include "Vector"

const int INF = 6500;


class Node {
    
    
public:
    
   
    
    template <class T>
    Node(Location<int> location);
   
    
    ~Node();
    
   
    Location<int> getLocation();
    
    Node* getparent();
    
    void setparent(Node* const parent);
    
    bool isWall(Direction heading);
    
    void setWall(Direction heading);
    
    void resetWall(Direction heading);
    
    int getC();
    
    int getH();
    
    bool isExplored();
    
    void setExplored();
    
    
    
    
    
private:
    
    Location<int> location;
    
    std::vector<Location<int>> neighbors;
    
    Node* parent;
    
    int cost_so_far = INF;
    
    int hurestic    = INF;
    
    bool explored = false;
    
    bool wall[4] = {true,true,true,true};
    
    
};

#endif /* Node_hpp */
