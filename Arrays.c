//#include<iostream.h>
#include<stdio.h>
//using namespace std;
int A[5];//bss in memory not initialized
/*
memory sections
Heap  pointers mallocs reallocs
stack static and global variables
int main(int argc, char const *argv[]) {

  return 0;
and code section.
}
*/
int main()
{
  int B[2]={1,2};//go to code section in memory,4 bytes for each
  //integer is 4 bytes in modern compilers
  //initialized so in  data segment
  printf("\nHello World\n\n");
  for(int i=0;i<2;i++)
    printf("%d\n",B[i]);
  A[1] = 5;
  printf("%d\n",sizeof(A));
  //cout<<sizeof(A)<<endl;
  //cout<<A[1];

  return 0;
}
