/*
 * Cell.h
 *
 *  Created on: 18.07.2017
 *      Author: Eckalibyr
 */

#ifndef CELL_H_
#define CELL_H_

#include <iostream>
#include <utility>

using namespace std;

class cell{ //class Cell
	int x; //points on the sheet
	int y;
	bool state; //state of the cell
public:
	pair<int, int> XandY; //object with points

	void CellSetXandY(int, int); //methods
	void CellSetState(bool);
	pair<int, int> CellGetXandY();
	bool CellGetState();
};

#endif /* CELL_H_ */
