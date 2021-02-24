#include <stdio.h>
#include <stdlib.h>
//#define EMPTY_ARRAY(self) Array self = {.type = UNKOWN,.size = 0, .length = 0}
#define DATA_TYPE_STR(dataType)                               \
    (INT == dataType ? "int" : (FLOAT == dataType ? "float" : \
    (CHAR == dataType ? "char" : (DOUBLE == dataType ? "double" : "unknown"))))

typedef enum t_dataType
{
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    UNKOWN
}
DataType;
//Value converter between data types
typedef union _candidate{
    void* voidType;
    int* intType;
    char *charType;
    float *floatType;
    double *doubleType;
} Candidate;

typedef struct _Array
{
    DataType type;
    Candidate candidate;
    union
    {
        int *iPtr;
        float *fPtr;
        char *cPtr;
        double *dPtr;
    };
    int capacity;
    int length;
    float growthRate;
} Array;
/**
 * Constructor for Array
 * */
// #define newArray(capacity,T)  _newArray(capacity,T);
static Array newArray(int capacity,DataType type)
{
    Array newArr;
    newArr.capacity = capacity;
    newArr.length = 0;
    newArr.type = type;
    switch (type)
    {
    case INT:
        newArr.iPtr = (int *)malloc(capacity * sizeof(int));
        break;
    case FLOAT:
        newArr.fPtr = (float *)malloc(capacity * sizeof(float));
        break;
    case CHAR:
        newArr.cPtr = (char *)malloc(capacity * sizeof(char));
        break;
    default:
        break;
    }
    return newArr;
}
/**
 * generates random values in array
 * */
void randomizeArray(Array *self, unsigned int seed);

/* prints values in an array*/
void displayArray(Array *self);

void destructArray(Array *self);

#define appendToArray(self, value) ({_setCandidate(self,&value); _appendToArray(self); });
static void _appendToArray(Array *self);
static void _setCandidate(Array *self, void *value)
{
    self->candidate.voidType = value;
}