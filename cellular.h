#include "rules.h"
#include "world.h"

#ifndef Cellular_H
#define Cellular_H

class Cellular {
public:
    Cellular( int w, int h );
    ~Cellular();
    
    void start( int r );
    
private:
    void display();
    void generation();
    
private:
    Rule *p_Rule;
    World *p_World;
    int gen; 
};

#endif
