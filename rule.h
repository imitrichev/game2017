/*
 * Rule.h
 *
 *  Created on: 18.07.2017
 *      Author: student
 */

#define RULE_H_
using namespace std;
#include <iostream.h>
class Rule {
public:
	virtual void apply(bool,int)=0;
};

class Rule5: public Rule {
public:
	virtual void apply (bool,int);
};

class RuleLife: public Rule {
public:
	virtual void apply(bool,int);
};
