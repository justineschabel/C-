#include <iostream>
#include "LongInt.h"

using namespace std;

istream& operator >> (istream  &input, LongInt& f) {
		
	char d = cin.peek();
	while(d != '\n'){ 
		if(isdigit(d) ){
			input >> d;
    			f.numList.push(d);
    			d = cin.peek(); 
    		}
    	}
	cin.get();
	return input;
}

 ostream& operator << (ostream& os, LongInt& r) {

 	while(!(r.numList.isEmpty())){
		char charVal = r.numList.top(); 
		//cout<<r.numList.top();
		os << charVal;
		r.numList.pop(); 
	}
	return os; 
 }

LongInt operator+(LongInt& fir, LongInt& sec){
	LongInt result; 
	int carry = 0;
 	int temp = 0;
								
	while(!(fir.numList.isEmpty()) && !(sec.numList.isEmpty())){	
		
		char a = fir.numList.topAndPop();
		int ai = a - '0';
		char b = sec.numList.topAndPop();
		int bi = b - '0';
		temp = ai + bi + carry;	

 		if(temp > 9){
			carry = 1; 
 		 	temp = temp - 10;			
 		}
		else{
			carry = 0;
		}
		char fin = temp + '0';
		result.numList.push(fin);
	}

	while(!(fir.numList.isEmpty())){
		char val = fir.numList.top();
		int valI = val - '0';

		if(carry == 1)
			valI++;
		if(valI > 9){
			carry = 1; 
 		 	valI = valI - 10;			
 		}	
 		else
 			carry = 0;

 		char valIC = valI + '0';

		result.numList.push(valIC);
		fir.numList.pop(); 
 	}

	while(!(sec.numList.isEmpty())){
		char val2 = sec.numList.top();
		int val2I = val2 - '0';
		if(carry == 1)
			val2I++;
		if(val2I > 9){
			carry = 1; 
 		 	val2I = val2I - 10;			
 		}	
 		else
 			carry = 0;

 		char val2IC = val2I + '0';

		result.numList.push(val2IC);
		sec.numList.pop();
 	}

	if(carry == 1){
		char lastCarry = 1 + '0';
		result.numList.push(lastCarry);
	}
		
	return result; 
}

LongInt& LongInt::operator=(const LongInt& rhs){

	this->numList = rhs.numList;

	return *this; 
}

void carry ();
