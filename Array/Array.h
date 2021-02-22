#include <stdio.h>
#include <stdlib.h>
#define EMPTY_ARRAY(self) Array self = {.type = UNKOWN,.size = 0, .length = 0}
#define DATA_TYPE_STR(dataType) \
    (INT == dataType ? "int" : (FLOAT == dataType ? "float" : \
    (CHAR == dataType ? "char" :  "unknown")))
typedef enum dataType
{
    INT,
    FLOAT,
    CHAR,
    UNKOWN
} DataType;

typedef struct Array
{
    DataType type;
    union
    {
        int *iPtr;
        float *fPtr;
        char *cPtr;
    };
    int size;
    int length;
} Array;
/**
 * Constructor for Array
 * */
Array newArray(int size, DataType type)
{
    Array newArr;
    newArr.size = size;
    newArr.length = 0;
    newArr.type = type;
    switch (type)
    {
    case INT:
        newArr.iPtr = (int *)malloc(size * sizeof(int));
        break;
    case FLOAT:
        newArr.fPtr = (float *)malloc(size * sizeof(float));
        break;
    case CHAR:
        newArr.cPtr = (char *)malloc(size * sizeof(char));
        break;
    default:
        break;
    }
    return newArr;
}
/**
 * generates random values in array
 * */
void randomizeArray(Array *self, unsigned int seed)
{
    srand(seed);
    for (int i = 0; i < self->size; i++)
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

    self->length = self->size - 1;
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
void appendToArray(Array *self, void* value)
{
    if (self->length == self->size)
        return;
    switch (self->type)
    {
    case INT:
        self->iPtr[self->length] = *((int *)value);
        break;
    case FLOAT:
        self->fPtr[self->length] = *((float *)value);
        break;
    case CHAR:
        self->cPtr[self->length] = *((char *)value);
        break;
    default:
        break;
    }
    self->length++;
}