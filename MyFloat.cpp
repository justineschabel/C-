/*
	Implements floating point add and subtract without using the 
	hardware's floating point or double precision add. 
	MyFloat represents a float using three unsigned  integers: sign, exponent, and mantissa.

	@Arg1 is a floating point number
	@Arg2 is either + or -
	@Arg3 is another floating point number

*/


#include "MyFloat.h"
#include "stdbool.h"
#include <algorithm>

MyFloat::MyFloat(){
  sign = 0;
  exponent = 0;
  mantissa = 0;
}

MyFloat::MyFloat(float f){
  unpackFloat(f);
}

MyFloat::MyFloat(const MyFloat & rhs){
	sign = rhs.sign;
	exponent = rhs.exponent;
	mantissa = rhs.mantissa;
}

ostream& operator<<(std::ostream &strm, const MyFloat &f){
	strm << f.packFloat();
	return strm;

}

bool MyFloat::operator==(const float rhs) const{
	if(packFloat() == rhs){//if the right hand side of the operator matches the current object return true (they are compared as floats)
		return true;
	}
	else{
		return false;
	}
}

MyFloat MyFloat::operator+(const MyFloat& rhs) const{

	int diff = 0;
	MyFloat bigger(*this); //Initializes the bigger values (sign, exponent, mantissa) for *this
	MyFloat smaller(rhs); //Initializes the smaller values (sign, exponent, mantissa) for rhs  
	MyFloat sum;

	//If the sign is different and theres a borrow, this variable is used 
	bool will_borrow = false; 

    //if the signs are different but the exponent and mantissa are the same, they will cancel out to 0: 1 + -1
	if((rhs.sign != this->sign) && (rhs.mantissa == this->mantissa) && (rhs.exponent == this->exponent)) {
		return sum; //returns 0
	}

	//After initializing the values, if the other one is bigger, switch them
	if(smaller.exponent > bigger.exponent){ 
		std::swap(smaller,bigger);	
	}
	//if the exponents are equal, judge bigger v. smaller based on the mantissa
	else if(smaller.exponent == bigger.exponent){
		if (smaller.mantissa > bigger.mantissa){
			std::swap(smaller,bigger);
		}
	}

	//change the 24th bit of the mantissa to 1
	bigger.mantissa |= 1<<23;	
	smaller.mantissa |= 1<<23; 

	//Find the difference between the exponents: bigger exponent - smaller exponent 
	diff = bigger.exponent - smaller.exponent; 

	
	//we need to make the exponents on the floats the same to add them. If the difference is greater than 31 though, the number is 0, so it is a special case 
	if (diff > 31){
		smaller.mantissa= 0;
		smaller.exponent = 0; 
	}
	
    //we will shift the mantissa by the difference between the exponents. However, if there is a subtraction, we need to check the value of the last bit shifted out for a borrow
	if(smaller.mantissa & (1<<(diff-1))) {
		will_borrow = true;
	}
	
	
	//if both numbers have the same sign, adjust the smaller number to have the same exponent, and then add the mantissas to get the sum
	smaller.mantissa = smaller.mantissa >> diff; //we are making the mantissa smaller
		
	//if the signs are different, we need to subtract the smaller number from the bigger number and find the difference
	//In subtraction we need to check for a borrow. So if the most significant bit that is shifted out is a 1, we need to subtract one from the mantissa at the end
	if(smaller.sign == bigger.sign) {
		sum.mantissa = bigger.mantissa + smaller.mantissa;
	}
	else {
		sum.mantissa = bigger.mantissa - smaller.mantissa;

		if (will_borrow) {
			sum.mantissa -= 1; //If there was a borrow in the subtraction we need to subtract one from the mantissa 
		}
	}

	sum.sign = bigger.sign; //set new float's sign
	sum.exponent = bigger.exponent; //set new float's exponent

	sum.normalize(); 
	
	return sum; 
} //end of operator+

//This function find the most significant bit of the mantissa of a MyFloat object. It then alters the mantissa to be in a "normalized" form (i.e. .mantissa)
void MyFloat::normalize(){
	for(int i = 24; i > 0; i--){ //start at the highest bit of the mantissa. This is the 25th bit becuse the addition of two 24 bit numbers can possible result in a 25 bit number
		if (mantissa & (1<<i)){ //if the msb is found, we need to see if it is to the left or the right of 23 because that will determine where we shift the mantissa
			if(i > 23){ //if its greater than 23 it was either the 24th or 23rd bit. so we shift it to the right, and add to the exponent to account for that
				mantissa = mantissa >> (i-23);
				exponent = exponent + (i-23);
				break;
			}
			else{ //otherwise the msb was found to the left or at bit 22. Therefore we shift it over and decrease the exponent
				mantissa = mantissa << (23-i); 
				exponent = exponent - (23-i); 
				break; 

			}
		}
	
	}
    //now that the mantissa is in the form 1.mantissa, delete the one to "normalize" it
 	mantissa = mantissa & ~(1<<23); 

}


MyFloat MyFloat::operator-(const MyFloat& rhs) const {

	MyFloat flipped = 0; 
	flipped.sign = 0; 
	flipped.mantissa = rhs.mantissa;
	flipped.exponent = rhs.exponent;
    //switch the sign of the right hand side (the values come in as positive so 1 + 1 becomes 1 + -1
	if(rhs.sign == 0){
		flipped.sign = 1;
	}
	else {
		flipped.sign = 0;
	}

	return *this + flipped; //add them together( +1 + -1)
}


//Given a float f this function should set sign, exponent, and mantissa to the
//appropriate values based on the value of f.
//Inline Assembly
void MyFloat::unpackFloat(float f) {
/*    
    mantissa =  f & 0x7fffff; //lower 23 bits all 1's
    exponent = (f & 0x7f800000) >> 23;
    sign =  f >> 31;
*/
	__asm__(
	//assembly code 
	"movl $0x7fffff, %%edi;" //edi = 0x7fffff
	"andl %[f], %%edi;" //edi has mantissa

	"movl $0x7f800000, %%ecx;" //ecx = 0x7fffff
	"andl %[f], %%ecx;" //f & 0x7f800000
	"shrl $23, %%ecx;" // ecx has exponent
	"movl %[f], %%ebx;"
	"shrl $31, %%ebx" ://ebx has sign 
	

	//outputs 
	"=D" (mantissa), 
	"=b" (sign), 
	"=c" (exponent) :

	//input
		[f] "a" (f):
	"cc"
	);

}//unpackFloat

//This function should return the floating point representation of MyFloat
//Inline Assembly
float MyFloat::packFloat() const{
  //returns the floating point number represented by this
  float f = 0;
  //f.mantissa = mantissa;
  //f.sign = sign
  //f.exponent = exponent
  __asm__(
  //assembly
  "movl %[sign], %[f];"
  "shll $8 , %[f];"
  "orl %[exponent], %[f];" //put the exponent into f (bits 23-30)
  "shll $23 , %[f];"
  "orl %[mantissa], %[f]"  ://put the mantissa into f(bits 0-22)
  
  //outputs
  	[f] "=a" (f):
  //inputs
  	[mantissa] "D" (mantissa), [sign] "b" (sign), [exponent] "c" (exponent) :

  	"cc"
	);

  return f;
}//packFloat
//

