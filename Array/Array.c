#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
int main()
{
    struct Array arr = newArray(5,INT_ARRAY);
    randomizeArray(&arr, time(0));
    displayArray(&arr);
    printf("\n");
    struct Array fArr = newArray(5, FLOAT_ARRAY);
    randomizeArray(&fArr, time(0));
    displayArray(&fArr);
    printf("\n");
    struct Array cArr = newArray(5, CHAR_ARRAY);
    randomizeArray(&cArr, time(0));
    displayArray(&cArr);
    
    destructArray(&arr);
    destructArray(&fArr);
    destructArray(&cArr);
    printf("%d",cArr.size);
    displayArray(&cArr);
    return 0;
}
