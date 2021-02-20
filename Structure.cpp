#include<stdio.h>
#include<iostream>
using namespace std;

struct Rectangle
{
  int length; //4 bytes
  int breadth; //4 bytes
  char x;//it will take extra memory, char will consume 4 byte as well called padding
};

struct ComplexNumber
{
  int real;
  int img;
};

struct Student
{
  int roll;
  char name[25]; //each char is 1 byte
};
struct Card
{
  int face;
  int shape;
  int color;
}card1,card2; // u can declare here as global variable
struct Rectangle r1;
int main() {
  //now occupies memory
  struct Rectangle r2={2,4};
  struct Card deck[52];
  r1.length = 5;
  r1.breadth = 10;
  printf("%d\n",r1.length*r1.breadth);
  printf("%d\n",r2.length*r2.breadth);
  struct Student s;
  s.roll = 1;
  printf("%d\n",s.roll);
  printf("%d\n",sizeof(r1));
  //create in heap
  Rectangle *rec = new Rectangle();
  rec->length = 5;
  rec->breadth = 5;
  printf("%d\n",rec->length*rec->breadth);
  return 0;
}
