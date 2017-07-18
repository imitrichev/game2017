/*
 * rule.h
 *
 *  Created on: 18.07.2017
 *      Author: student
 */

#define RULE_H_
using namespace std;
#include <iostream.h>
class rule {
public:
	virtual void apply(bool,int)=0;
};

class Rule5: public rule {
public:
	virtual void apply (bool,int);
};

class RuleLife: public rule {
public:
	virtual void apply(bool,int);
};




