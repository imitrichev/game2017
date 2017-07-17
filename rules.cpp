#include "rules.h"
#include <algorithm>
#include <iostream>

Rule::Rule( World* p_World ) : p_wrd( p_World ) {
        m_Width = p_wrd->getWidth();
        m_Height = p_wrd->getHeight();
        p_wrdT = new World( m_Width, m_Height );
    }
    
Rule::~Rule() {
        if( p_wrdT ) delete p_wrdT;
    }
    
bool Rule::hasLivingCells() 
{
        for( int y = 0; y < m_Height; y++ )
            for( int x = 0; x < m_Width; x++ )
                if( p_wrd->at( x, y ) ) return true;
        std::cout << "*** All cells are dead!!! ***\n\n";
        return false;
}

void Rule::swapWrds() 
{
        p_wrd->swap( p_wrdT );
}

void Rule::setRuleB( std::vector<int>& birth ) 
{
        m_Birth = birth;
}

void Rule::setRuleS( std::vector<int>& stay ) 
{
        m_Stay = stay;
}

void Rule::applyRules() {
        int n;
        for( int y = 0; y < m_Height; y++ ) {
            for( int x = 0; x < m_Width; x++ ) {
                n = neighbours( x, y );
                if( p_wrd->at( x, y ) ) {
                    p_wrdT->set( x, y, inStay( n ) ? 1 : 0 );
                } else {
                    p_wrdT->set( x, y, inBirth( n ) ? 1 : 0 );
                }
            }
        }
}

int Rule::neighbours( int xx, int yy ) {
        int n = 0, nx, ny;
        for( int y = -1; y < 2; y++ ) {
            for( int x = -1; x < 2; x++ ) {
                if( !x && !y ) continue;
                nx = ( m_Width + xx + x ) % m_Width;
                ny = ( m_Height + yy + y ) % m_Height;
                n += p_wrd->at( nx, ny ) > 0 ? 1 : 0;
            }
        }
        return n;
}

bool Rule::inStay( int n ) 
{
        return( m_Stay.end() != std::find( m_Stay.begin(), m_Stay.end(), n ) );
}

bool Rule::inBirth( int n ) 
{
        return( m_Birth.end() != std::find( m_Birth.begin(), m_Birth.end(), n ) );
}

