#include<iostream>
#include<stdio.h>
using namespace std;
int A[5] = {1};//bss in memory not initialized
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
  //int B[2]={1,2};//go to code section in memory,4 bytes for each
  //integer is 4 bytes in modern compilers
  //initialized so in  data segment
  // printf("\nHello World\n\n");
  // for(int i=0;i<2;i++)
  //   printf("%d\n",B[i]);
  // A[1] = 5;
  // for(int x:A){
  //   std::cout << x << '\n';
  // }
  int n;
  std::cout << "Enter Size" << '\n';
  std::cin >> n;
 
  for(int x:A){
    std::cout << x << '\n';
  }
  cout<<sizeof(A)<<endl;
  cout<<A[1];
  //2D Arrays
  int B[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {5, 10, 15, 20}};//all in stack
  int *C[3]; //2D array
  C[0] = new int[4];
  int **D; //2D array
  D = new int*[3];
  D[0] = new int[4];
  return 0;
}
