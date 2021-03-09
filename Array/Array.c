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

    self->length = self->capacity;
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
    free(self->iPtr);
    self->length = 0;
    self->capacity = 0;
}
static void _appendToArray(Array *self, void *value)
{
    Candidate candidate;
    candidate.voidType = value;
    if (self->length == self->capacity)
        _resize(self);
    // self->candidate.voidType = value;
    switch (self->type)
    {
    case INT:
        self->iPtr[self->length] = *(candidate.intType);
        //*((int *)value);
        break;
    case FLOAT:
        self->fPtr[self->length] = *(candidate.floatType);
        //*((float *)value);
        break;
    case CHAR:
        self->cPtr[self->length] = *(candidate.charType);
        break;
    case DOUBLE:
        self->cPtr[self->length] = *(candidate.doubleType);
        break;
    default:
        break;
    }
    self->length++;
    // free(candidate.voidType);
    candidate.voidType = NULL;
}
static void _insertToArray(Array *self, int index, void *value)
{
    if (self->length == self->capacity)
        _resize(self);
    //shift array elements
    for (int i = self->length; i > index; i--)
        switch (self->type)
        {
        case INT:
            self->iPtr[i] = self->iPtr[i - 1];
            break;
        case FLOAT:
            self->fPtr[i] = self->fPtr[i - 1];
            break;
        case CHAR:
            self->cPtr[i] = self->cPtr[i - 1];
            break;
        case DOUBLE:
            self->dPtr[i] = self->dPtr[i - 1];
            break;
        default:
            break;
        }
    _setArrayIndex(self, index, value);
    self->length++;
}
void _setArrayIndex(Array *self, int index, void *value)
{
    Candidate candidate;
    candidate.voidType = value;
    switch (self->type)
    {
    case INT:
        self->iPtr[index] = *(candidate.intType);
        break;
    case FLOAT:
        self->fPtr[index] = *(candidate.floatType);
        break;
    case CHAR:
        self->cPtr[index] = *(candidate.charType);
        break;
    case DOUBLE:
        self->dPtr[index] = *(candidate.doubleType);
        break;
    default:
        break;
    }
    candidate.voidType = NULL;
}

void removeFromArray(Array *self, int index)
{
    if (index >= self->length || index < 0)
        return;
    for (int i = index; i < self->length - 1; i++)
        switch (self->type)
        {
        case INT:
            self->iPtr[i] = self->iPtr[i + 1];
            //*((int *)value);
            break;
        case FLOAT:
            self->fPtr[i] = self->fPtr[i + 1];
            //*((float *)value);
            break;
        case CHAR:
            self->cPtr[i] = self->cPtr[i + 1];
            break;
        case DOUBLE:
            self->dPtr[i] = self->dPtr[i + 1];
            break;
        default:
            break;
        }
    self->length--;
}
//move to head
static int _linearSearch(Array *self, void *value)
{
    Candidate candidate;
    candidate.voidType = value;
    if (self->type != INT)
        return -1;
    for (int i = 0; i < self->length; i++)
        switch (self->type)
        {
        case INT:
            if (self->iPtr[i] == *(candidate.intType))
            {
                if (i > 0)
                    swap(self->iPtr[i], self->iPtr[0]);
                return 0;
            }
            //*((int *)value);
        case FLOAT:
            if (self->fPtr[i] == *(candidate.floatType))
            {
                if (i > 0)
                    swap(self->fPtr[i], self->fPtr[0]);
                return 0;
            }
            //*((float *)value);
            break;
        case CHAR:
            if (self->cPtr[i] == *(candidate.charType))
            {
                if (i > 0)
                    swap(self->cPtr[i], self->cPtr[0]);
                return 0;
            }
            break;
        case DOUBLE:
            if (self->dPtr[i] == *(candidate.doubleType))
            {
                if (i > 0)
                    swap(self->dPtr[i], self->dPtr[0]);
                return 0;
            }
        default:
            break;
        }
    return -1;
}

static int _binarySearch(Array *self, void *value)
{
    Candidate candidate;
    candidate.voidType = value;
    int first = 0;
    int last = self->length - 1;
    int midIndex = 0;
    do
    {
        midIndex = median(first, last);
        switch (self->type)
        {
        case INT:
            printf("condition [%d],  %d == %d \n", midIndex, self->iPtr[midIndex], *(candidate.intType));
            if (self->iPtr[midIndex] == *(candidate.intType))
                return midIndex;
            else if (self->iPtr[midIndex] > *(candidate.intType))
                last = midIndex - 1;
            else if (self->iPtr[midIndex] < *(candidate.intType))
                first = midIndex + 1;
            break;
        case FLOAT:
            if (self->fPtr[midIndex] == *(candidate.floatType))
                return midIndex;
            else if (self->fPtr[midIndex] > *(candidate.floatType))
                last = midIndex - 1;
            else if (self->fPtr[midIndex] < *(candidate.floatType))
                first = midIndex + 1;
            break;
        case CHAR:
            if (self->cPtr[midIndex] == *(candidate.charType))
                return midIndex;
            else if (self->cPtr[midIndex] > *(candidate.charType))
                last = midIndex - 1;
            else if (self->cPtr[midIndex] < *(candidate.charType))
                first = midIndex + 1;
            break;
        case DOUBLE:
            if (self->dPtr[midIndex] == *(candidate.doubleType))
                return midIndex;
            else if (self->dPtr[midIndex] > *(candidate.doubleType))
                last = midIndex - 1;
            else if (self->dPtr[midIndex] < *(candidate.doubleType))
                first = midIndex + 1;
            break;
        default:
            return -1;
        }

    } while (first <= last);
    return -1;
}

void reverse(Array *self){
    if(self->length<2)
        return;
    switch (self->type)
    {
    case INT:
        for (int i = 0,j=self->length-1; i < self->length/2;i++,j--)
            swap(self->iPtr[i], self->iPtr[j]);
        break;
        case FLOAT:
            for (int i = 0, j = self->length - 1; i < self->length / 2; i++, j--)
                swap(self->fPtr[i], self->fPtr[j]);
            break;
        case CHAR:
            for (int i = 0, j = self->length - 1; i < self->length / 2; i++, j--)
                swap(self->cPtr[i], self->cPtr[j]);
            break;
        case DOUBLE:
            for (int i = 0, j = self->length - 1; i < self->length / 2; i++, j--)
                swap(self->dPtr[i], self->dPtr[j]);
            break;
        }
}

int main()
{

    Array iArr = newArray(10, INT);
    Array fArr = newArray(10, FLOAT);
    for (int i = 0; i < iArr.capacity; i++)
        appendToArray(&iArr, i);
    for (int i = 0; i < fArr.capacity; i++)
    {
        float j = (float)i + 0.5;
        appendToArray(&fArr, j);
    }
    displayArray(&iArr);
    int x = 9;
    int y = 5;
    float t = 3.5;

    printf("number %d is at index %d\n", x, binarySearch(&iArr, x));
    printf("number %f is at index %d\n", t, binarySearch(&fArr, t));
    int result = get(&iArr, 4);
    float resultf = get(&fArr, 3);
    printf("value at index 4 is %d\n", result);
    printf("value at index 3 is %f\n", resultf);
    set(&iArr, 8, 20);
    result = min(2,2);
    printf("value at index 8 is %d\n",result);
    // reverse(&iArr);
    destructArray(&iArr);
    destructArray(&fArr);
    return 0;
}
