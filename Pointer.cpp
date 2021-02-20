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
  p2 = new int[5];
  printf("p2 address at init %d\n",&p2);
  for (size_t i = 0; i < 5; i++) {
    p2[i]=i*5;
    printf("%d\n",p2[i]);
  }
  delete [ ] p2;
  printf("p2 address after delete %d\n",&p2);
  //when program ends heap will be automatically deleted
  return 0;
}
