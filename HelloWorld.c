#include<stdio.h>
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
  int B[2]={1,2};//go to code section in memory,2 bytes for each
  //initialized so in  data segment
  printf("\nHello World\n\n");
  return 0;
}
