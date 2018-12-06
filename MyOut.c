//This program calculates the output of a function based on a value n
//based on fib but with doubles
////libraries
#include <stdio.h>
#include <stdlib.h>

//declare functions
int foo(int n);
int _foo(int n, int n3, int n2, int n1);

//call recursive function with base values
int foo(int n){
    
    return _foo(n, 2, 3, 5);
    
}


int _foo(int n, int n3, int n2, int n1){
    
    if(n == 0){
        return n3; //returns 2 initially
    }
    else if(n == 1){//returns 3 initially
        return n2 ;
    }
    else if(n == 2){//returns 5 initially
        return n1 ;
    }
    else{
        //n-3 becomes n-2, n-2 becomes n-1, new number is a combination of the last three
        return _foo(n-1, n2, n1, n1+n2+n3 );
    }
}

int main(int argc, char** argv){
    printf("foo(%d) = %d\n", atoi(argv[1]), foo(atoi(argv[1])));
    return 0;
}
