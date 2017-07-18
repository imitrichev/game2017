//============================================================================
// Name        : Cell.cpp
// Author      : Eckalibyr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Cell.h"

//description of methods for class "cell"

void cell::CellSetXandY(int In_x, int In_y){
	x = In_x;
	y = In_y;
}

void cell::CellSetState(bool Inputed_State){
	state = Inputed_State;
}

pair<int, int> cell::CellGetXandY(){
	return pair<int, int>(x , y);
}

bool cell::CellGetState(){
	return state;
}
