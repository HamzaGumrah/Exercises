#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Array.h"

void randomizeArray(Array *self, unsigned int seed)
{
    srand(seed);
    for (int i = 0; i < self->capacity; i++)
        switch (self->type)
        {
        case INT:
            self->iPtr[i] = rand();
            break;
        case FLOAT:
            self->fPtr[i] = ((float)rand() / (float)(RAND_MAX)) * 10;
            break;
        case CHAR:
            self->cPtr[i] = 'A' + (random() % 26);
            break;
        default:
            break;
        }

    self->length = self->capacity ;
}

/* prints values in an array*/
void displayArray(Array *self)
{
    for (int i = 0; i < self->length; i++)
        switch (self->type)
        {
        case INT:
            printf("[%d] = %d\n", i, self->iPtr[i]);
            break;
        case FLOAT:
            printf("[%d] = %f\n", i, self->fPtr[i]);
            break;
        case CHAR:
            printf("[%d] = %c\n", i, self->cPtr[i]);
            break;
        case DOUBLE:
            printf("[%d] = %f\n", i, self->dPtr[i]);
            break;
        default:
            break;
        }
}

void destructArray(Array *self)
{
    switch (self->type)
    {
    case INT:
        free(self->iPtr);
        printf("Deleted INT array\n");
        break;
    case FLOAT:
        free(self->fPtr);
        printf("Deleted FLOAT array\n");
        break;
    case CHAR:
        free(self->cPtr);
        printf("Deleted CHAR array\n");
        break;
    default:
        break;
    }
    self->length = 0;
}
static void _appendToArray(Array *self)
{
    if (self->length == self->capacity)
        _resize(self);
    // self->candidate.voidType = value;
    switch (self->type)
    {
    case INT:
        self->iPtr[self->length] = *(self->candidate.intType);
        //*((int *)value);
        break;
    case FLOAT:
        self->fPtr[self->length] = *(self->candidate.floatType);
        //*((float *)value);
        break;
    case CHAR:
        self->cPtr[self->length] = *(self->candidate.charType);
        break;
    case DOUBLE:
        self->cPtr[self->length] = *(self->candidate.doubleType);
        break;
    default:
        break;
    }
    self->length++;
}
static void _insertToArray(Array *self, int index){
    if (self->length == self->capacity)
        _resize(self);
    //shift array elements
    for (int i = self->length; i > index;i--)
        switch (self->type)
        {
        case INT:
            self->iPtr[i] = self->iPtr[i - 1];
            break;
        case FLOAT:
            self->fPtr[i] = self->fPtr[i-1];
            break;
        case CHAR:
            self->cPtr[i] = self->cPtr[i-1];
            break;
        case DOUBLE:
            self->dPtr[i] = self->dPtr[i-1];
            break;
        default:
            break;
        }
    _setArrayIndex(self,index);
    self->length++;
}
void  _setArrayIndex(Array *self,int index){
    switch (self->type)
    {
    case INT:
        self->iPtr[index] = *(self->candidate.intType);
        break;
    case FLOAT:
        self->fPtr[index] = *(self->candidate.floatType);
        break;
    case CHAR:
        self->cPtr[index] = *(self->candidate.charType);
        break;
    case DOUBLE:
        self->dPtr[index] = *(self->candidate.doubleType);
        break;
    default:
        break;
    }
}

void removeFromArray(Array *self, int index){
    if(index>=self->length || index < 0)
        return;
    for (int i = index; i < self->length-1;i++)
        switch (self->type)
        {
        case INT:
            self->iPtr[i] = self->iPtr[i+1];
            //*((int *)value);
            break;
        case FLOAT:
            self->fPtr[i] = self->fPtr[i+1];
            //*((float *)value);
            break;
        case CHAR:
            self->cPtr[i] = self->cPtr[i+1];
            break;
        case DOUBLE:
            self->dPtr[i] = self->dPtr[i+1];
            break;
        default:
            break;
        }
    self->length--;
}
int main()
{
    // Array arr = newArray(5, INT);
    // randomizeArray(&arr, time(0));
    // displayArray(&arr);
    // printf("\n");
    Array fArr = newArray(5, FLOAT);
    randomizeArray(&fArr, time(0));
    // displayArray(&fArr);
    printf("\n");
    // Array cArr = newArray(5, CHAR);
    // randomizeArray(&cArr, time(0));
    // displayArray(&cArr);
    
  /*   destructArray(&arr);
    // destructArray(&fArr);
    destructArray(&cArr);
    displayArray(&cArr); */

    // Array array = newArray(10, INT);
    // printf("%s\n", DATA_TYPE_STR(array.type));
    // int x = 84;
    // int y = 32;
    float z = 2.5;
    // appendToArray(&array, x);
    // appendToArray(&array, y);
    // insertToArray(&array, 0, y);
    // displayArray(&array);
    appendToArray(&fArr, z);
 
 
    displayArray(&fArr);
    removeFromArray(&fArr, 3);
    removeFromArray(&fArr, 0);
    removeFromArray(&fArr, 8);
    removeFromArray(&fArr, -1);
    displayArray(&fArr);
    return 0;
}
