#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//grouping instructuions
//modules or procedures
//Parameter passing
// Pass by value
// Pass by address
// in c++ Pass by reference

//function in code section
int add(int a,int b){
  //when you call a function
  //it creates its own values in stack again
  //when function returns memory area for it clears
  //this is value pass function
  return a+b;
}
// value passing
// function is seperate in memory not part of main body
void swap2(int x,int y){
  printf("x = %d , y = %d \n",x,y );
  x=x+y;
  y=x-y;
  x=x-y;
  printf("x = %d , y = %d \n",x,y );
}
// address passing
// function is seperate in memory not part of main function
void swap1(int *x,int *y){
  printf("x = %d , y = %d \n",*x,*y );
  *x=*x+*y;
  *y=*x-*y;
  *x=*x-*y;
  printf("x = %d , y = %d \n",*x,*y );
}
//reference passing only in c++
//swap is not a different function in memory
//it has been part of main function
//machine code is monolithic
//source code is modular
//it should be use carefully , using it for  small functins is ok
//but for heavy functions address passsing prefered
//if only one parameter is call by reference it is not gonna be inline function
//depending on the compiler
void swap(int &x,int *y){
  printf("x = %d , y = %d \n",x,*y );
  x=x+*y;
  *y=x-*y;
  x=x-*y;
  printf("x = %d , y = %d \n",x,*y );
}

int main(int argc, char const *argv[]) {
  int a = 5,b = 10;
  printf("a = %d , b = %d \n",a,b );

  //swap1(&a,&b);
  swap(a,b);
  printf("a = %d , b = %d \n",a,b );
  // printf("Sum is %d ",add(5,10));
  return 0;
}
