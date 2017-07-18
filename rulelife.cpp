//============================================================================
// Name        : rulelife.cpp
// Author      : megatron028
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <rule.h>

bool apply(bool lifest, int kol){
	if(lifest == true){
		if ((kol != 2)&&(kol != 3)){
			return false;
		}
} else{
		if (kol == 3){
			return true;
		}
	}
}

