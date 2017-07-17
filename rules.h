#include <vector>
#include "world.h"

#ifndef Rule_H
#define Rule_H

class Rule {
public:
    Rule( World* p_World );
    ~Rule();
    
    bool hasLivingCells();
    void swapWrds();
    
    void setRuleB( std::vector<int>& birth );
    void setRuleS( std::vector<int>& stay );
    
    void applyRules();
    
private:
    int neighbours( int xx, int yy );
    
    bool inStay( int n );
    bool inBirth( int n );
    
private:
    int m_Width, m_Height;
    World *p_wrd, *p_wrdT;
    std::vector<int> m_Stay, m_Birth;
};

#endif
