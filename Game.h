/*
 * Cells.h
 *
 *  Created on: 18 èþëÿ 2017 ã.
 *      Author: Ãëåá
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;
	class Game{
	 public:
		vector <cell> cell;
		vector <QPushButton> button;
	 public:
		Game(){};
		void Create();
		void Start();
		void Update();
	    int countAlive(int x, int y);
		~Game(){};
	};
#endif /* CELLS_H_ */
