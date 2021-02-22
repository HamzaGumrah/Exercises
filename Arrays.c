//#include<iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define ARRAY_SIZE 1000000
#define REINIT_CYCLES 100
#define INT_SIZE sizeof(int)
//using namespace std;
int A[5]; //bss in memory not initialized
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
  unsigned long indexedTime, arithmaticTime;
  double ratio = 0;
  srand(time(0));

  struct timeval stop, start,start2,stop2;
  int cycle = 0;
  int *pointerTest = (int *)malloc(sizeof(INT_SIZE) * ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    *(pointerTest++) = i;
    // printf("[%d] = %d\n", i,*(pointerTest-1));
  }
  pointerTest = pointerTest - ARRAY_SIZE;
  printf("Start Address of pointer = %u\n", pointerTest);

  printf("\nRe - initialize with ordered numbers of ARRAY with SIZE %d [i] addressing\n", ARRAY_SIZE);
  printf("Init Cycles = %d\n", REINIT_CYCLES);
  cycle = 0;
  gettimeofday(&start, NULL);
  while (cycle < REINIT_CYCLES)
  {
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
      pointerTest[i] = i % 50;
    }
    cycle++;
  }
  gettimeofday(&stop, NULL);
  indexedTime = (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec;
  printf("RE-INIT %d times took %lu us\n", REINIT_CYCLES, indexedTime);

  // printf("End Address of pointer = %u\n", pointerTest);
  // pointerTest = pointerTest - ARRAY_SIZE;
  printf("\nStart Address of pointer = %u\n", pointerTest);
  printf("Re-initialize with ordered numbers  of ARRAY with SIZE %d Pointer Aritmatic\n", ARRAY_SIZE);
  printf("Init Cycles = %d\n", REINIT_CYCLES);
  gettimeofday(&start2, NULL);
  cycle = 0;
  int *endAdress = pointerTest + ARRAY_SIZE;
  while (cycle < REINIT_CYCLES)
  {
    do{
      *(pointerTest++) = cycle % 50;
    } while (pointerTest < endAdress);
    cycle++;
    pointerTest = pointerTest - ARRAY_SIZE;
  }
  gettimeofday(&stop2, NULL);
  arithmaticTime = (stop2.tv_sec - start2.tv_sec) * 1000000 + stop2.tv_usec - start2.tv_usec;
  printf("RE-INIT took %d , %lu us\n", REINIT_CYCLES, arithmaticTime);

 
  printf("\n<---Summary--->\n");
  if (indexedTime > arithmaticTime)
  {
    printf("Pointer Arithmatic is %lu Faster than index addressing \n", indexedTime - arithmaticTime);
    ratio = (double)indexedTime / arithmaticTime;
    printf("%f Times faster ", ratio);
  }
  else
  {
    printf("Index Addressing is %lu Faster than pointer arithmatic ", arithmaticTime - indexedTime);
    ratio = (double)arithmaticTime / indexedTime;
    printf("%f Times faster ", ratio);
  }
  printf("\nTesting random index value check \n");
  int index = rand() % 1000000;
  printf("Value at [%d] = %d \n", index, pointerTest[index]);
  printf("Value at *(p+%d) = %d \n", index, *(pointerTest + index));
  free(pointerTest);
  pointerTest = NULL;
  return 0;
}
