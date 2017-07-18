#include <iostream>
using namespace std;
class Rull5{
public:
    // lifest - текущее состояние клетки
    //kol - количество соседей
    bool apply(bool lifest, int kol){
    if(lifest==true){
        if((kol!=2) && (kol!=3) && (kol!=5)){
            return false;
        }
        else{
            if(kol==3){
                return true;
            }
        }
    }
    }
    };
