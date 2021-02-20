#include<stdio.h>
// #include<stdlib.h>
#include<iostream>
using namespace std;
//references are only available in c++

int main() {
  int a = 10;
  //now we have 2 names for same value in memory, they have same memory address
  int &r=a;//for parameter passing , initialize during declaration
  cout<<a<<endl;
  r++;
  cout<<a<<endl;
  cout<<r<<endl;

  int b = 25;
  r =b;
  cout<<a<<endl;
  cout<<r<<endl;
  //by concept it does not consume any memory
  //conceptually different from pointer

  return 0;
}
