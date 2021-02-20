#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// #include<math.h>
//grouping instructuions
//modules or procedures
//Parameter passing
//-> Pass by value
//-> Pass by address
//-> in c++ Pass by reference
struct Rectangle {
  int length;
  int breadth;
};

struct Test{
  //if you pass this struct by value to any function
  //array below will be created in memory again!!
  int T[5];
  int n;
};
//function in code section
int add(int a,int b){
  //when you call a function
  //it creates its own values in stack again
  //when function returns memory area for it clears
  //this is value pass function
  return a+b;
}
// value passing
void swap2(int x,int y){
  printf("x = %d , y = %d \n",x,y );
  x=x+y;
  y=x-y;
  x=x-y;
  printf("x = %d , y = %d \n",x,y );
}
// address passing
void swap(int *x,int *y){
  printf("x = %d , y = %d \n",*x,*y );
  *x=*x+*y;
  *y=*x-*y;
  *x=*x-*y;
  printf("x = %d , y = %d \n",*x,*y );
}
//arrays only pass by address
//int *A means any int , also can be array
//u need to pass size of array also , A[ ] this is pointer so size is 8 bytes
//does not matter the size
void fun(int A[],int n){
  int i = 0;
  //
  // printf("size in function %d ",sizeof(A)/sizeof(int));
  // srand(500);
  while(i<n){
    A[i] = rand()%100;
    printf("%d\n",A[i]);
    i++;
  }
}

int * fun2(int size)
{
  int *p = (int*)malloc(sizeof(int)*size);
  int i = 0;
  while(i<size){
    p[i] = rand()%100;
    printf("%d\n",p[i]);
    i++;
  }
  return p;
}
//Structure as Parameter by value
//!!If structure has an array , than array will be copied in memory again!!
//normally arrays are passed by address but when they are in structure
//they are passed by value
int area(struct Rectangle r){
  return r.length*r.breadth;
}
//Structure by address
void changeLength(struct Rectangle *p){
  p->length = rand()%20;
  printf("\nnew length is %d",p->length);
  printf("\narea of rectangle %d ",area(*p));
}
int main(int argc, char const *argv[]) {
  int a = 5,b = 10;
  srand(time(0));
  printf("a = %d , b = %d \n",a,b );
  swap(&a,&b);
  printf("a = %d , b = %d \n",a,b );
  // printf("Sum is %d ",add(5,10));
  int *B = fun2(5);
  printf("\nsize in main body %d \n",sizeof(B)/sizeof(int));
  // fun(B,5);
  struct Rectangle r={10,4};
  printf("\narea of rectangle %d ",area(r));
  changeLength(&r);
  printf("\nsize of int %d bytes",sizeof(int));
  printf("\nsize of pointer %d bytes\n",sizeof(int*));
  return 0;
}
