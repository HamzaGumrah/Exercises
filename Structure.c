#include<stdio.h>
#include<stdlib.h>
struct Rectangle
{
  int length; //4 bytes
  int breadth; //4 bytes
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
};
int main() {
  //now occupies memory
  struct Rectangle r1;
  struct Rectangle r2={2,4};
  struct Card deck[52];
  r1.length = 5;
  r1.breadth = 10;
  printf("%d\n",r1.length*r1.breadth);
  printf("%d\n",r2.length*r2.breadth);
  struct Student s;
  s.roll = 1;
  printf("%d\n",s.roll);
  //pointers with struct
  printf("\n************************\n");
  //this is in Stack memory
  struct Rectangle *p=&r1;
  //p.lenght and *p.lenght are WRONG!!!
  //both below are correct
  //(*p).length = 20 ;
  //p->length = 20;
  printf("%d\n",p->length*(*p).breadth);
  //now lets create in heap memory
  //malloc function returns a void pointer which is generic
  struct Rectangle *rec = (struct Rectangle*)malloc(sizeof(struct Rectangle));
  rec->length = 3;
  rec->breadth = 8;
  printf("rectangle object in heap ");
  printf("%d\n",rec->length*(*rec).breadth);

  return 0;
}
