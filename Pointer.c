#include<stdio.h>
#include<stdlib.h>
//pointers are address variables
//why need them ?
//program can directly access to stack and code section
//how to access to heap? with a pointer , All access to resources outside
//the program are handled by pointers
//They are also usefull for parameter passing

int a = 10; //data variables
int *p ; //address variablles
int main() {
  p = &a;
  printf("%d\n",a);
  printf("%d\n",*p);//referenceing to value
  printf("%d\n",p);//memory address of a    4210724
  printf("%d\n",&a);//memory address   4210724
  printf("%d\n",&p);//memory address of pointer itself 4210736
  //above example acess to data variable it is not in heap memory.
  //lets access to heap memory ->
  //all variable declarations will be in stack
  //when u write malloc you will go to heap !!
  int *p2;
  p2 = (int*)malloc(5*sizeof(int));
  //new int[5] in c++
  printf("%d\n",&p2);
  p2[1] = 78;
  for (size_t i = 0; i < 5; i++) {
    p2[i]=i*5;
    /* code */
  }
  printf("%d\n",p2[1]);

  int C[3]={9,23,4};
  int *p3;
  p3 = C;
  for (size_t i = 0; i < 5; i++) {
    printf("%d\n",p2[i]);
    /* code */
  }
  free(p2);//free memory at heap !!
  //when program ends heap will be automatically deleted
  char *cPointer;
  float *fPointer;
  double *dPointer;
  printf("%d\n",sizeof(cPointer));
  printf("%d\n",sizeof(fPointer));
  printf("%d\n",sizeof(dPointer));
  //all pointers are 8 bytes!! since they keep address
  //latest compilers are 8 bytes since 64 bit
  //size of pointer is not depended on data types 
  return 0;
}
