#include <iostream>
#include <string>
 using namespace std;

int main(){
  string str ("My String");
  string::iterator it;
  char strArray[str.length()];
  int index = 0;
  for ( it = str.begin() ; it < str.end(); it++ ,index++)
  {
         cout << index << *it ;
	 strArray[index] = *it; 
	cout<< "strArray: "<< strArray[index] << endl;
  }
}
