#include <iostream>
#include <string>
 using namespace std;
//This program puts a string into a character array, this would allow manipulation of the string
int main(){
  string str ("My String");
  string::iterator it;
  char strArray[str.length()];
  int index = 0;
  for ( it = str.begin() ; it < str.end(); it++ ,index++){
         index << *it ;
	 strArray[index] = *it; 
	 cout<< "strArray: "<< strArray[index] << endl;
  }
}
