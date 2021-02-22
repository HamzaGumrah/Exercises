#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
int main()
{
    struct Array arr = newArray(5,INT);
    randomizeArray(&arr, time(0));
    displayArray(&arr);
    printf("\n");
    struct Array fArr = newArray(5, FLOAT);
    randomizeArray(&fArr, time(0));
    displayArray(&fArr);
    printf("\n");
    struct Array cArr = newArray(5, CHAR);
    randomizeArray(&cArr, time(0));
    displayArray(&cArr);
    
    destructArray(&arr);
    destructArray(&fArr);
    destructArray(&cArr);
    displayArray(&cArr);
    EMPTY_ARRAY(array);
    printf("%s\n", DATA_TYPE_STR(array.type));
    array = newArray(10, INT);
    printf("%s\n", DATA_TYPE_STR(array.type));
    int x = 84;

    appendToArray(&array, &x);
    displayArray(&array);
    return 0;
}
