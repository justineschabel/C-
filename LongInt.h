#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include "LinkedList.h"
#include "StackLi.h"
#include "dsexceptions.h"
using namespace std;

class LongInt{

public:
	
	
	static int carry;
	friend LongInt operator+ (LongInt& fir, LongInt& sec); 
	friend ::ostream& operator << (ostream& os, LongInt& f);
   	friend ::istream& operator >> (istream  &num, LongInt& r);
	LongInt& operator=(const LongInt& rhs); 


private: 
	StackLi <char> numList;
    
};

#endif