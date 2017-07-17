#include "cellular.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

Cellular::Cellular( int w, int h ) : p_Rule( 0 )
{
        p_World = new World( w, h );
}

Cellular::~Cellular() 
{
        if( p_Rule ) delete p_Rule;
        delete p_World;
}

void Cellular::start( int r ) 
{
        p_Rule = new Rule( p_World );
        gen = 1;
        std::vector<int> t;
        switch( r ) {
            case 1: // conway
                t.push_back( 2 ); t.push_back( 3 ); p_Rule->setRuleS( t );
                t.clear(); t.push_back( 3 ); p_Rule->setRuleB( t );
                break;
            case 2: // amoeba
                t.push_back( 1 ); t.push_back( 3 ); t.push_back( 5 ); t.push_back( 8 ); p_Rule->setRuleS( t );
                t.clear(); t.push_back( 3 ); t.push_back( 5 ); t.push_back( 7 ); p_Rule->setRuleB( t );
                break;
            case 3: // life34
                t.push_back( 3 ); t.push_back( 4 ); p_Rule->setRuleS( t );
                p_Rule->setRuleB( t );
                break;
            case 4: // maze
                t.push_back( 1 ); t.push_back( 2 ); t.push_back( 3 ); t.push_back( 4 ); t.push_back( 5 ); p_Rule->setRuleS( t );
                t.clear(); t.push_back( 3 ); p_Rule->setRuleB( t );
                break;
        }
 
        /* just for test - shoud read from a file */
        /* GLIDER */
        p_World->set( 6, 1, 1 ); p_World->set( 7, 2, 1 );
        p_World->set( 5, 3, 1 ); p_World->set( 6, 3, 1 );
        p_World->set( 7, 3, 1 );
        /* BLINKER */
        p_World->set( 1, 3, 1 ); p_World->set( 2, 3, 1 );
        p_World->set( 3, 3, 1 );
        /******************************************/
        generation();
}

void Cellular::display() 
{
        system( "cls" );
        int m_Width = p_World->getWidth();
        int m_Height = p_World->getHeight();
        
        std::cout << "+" << std::string( m_Width, '-' ) << "+\n";
        for( int y = 0; y < m_Height; y++ ) {
            std::cout << "|";
            for( int x = 0; x < m_Width; x++ ) {
                if( p_World->at( x, y ) ) std::cout << "#";
                else std::cout << ".";
            }
            std::cout << "|\n";
        }
        std::cout << "+" << std::string( m_Width, '-' ) << "+\n";
        std::cout << "Generation: " << gen << "\n\nPress [RETURN] for the next generation...";
        std::cin.get();
}
    
void Cellular::generation() 
{
        do {
            display();
            p_Rule->applyRules();
            p_Rule->swapWrds();
            gen++;
        }
        while ( p_Rule->hasLivingCells() );
}
