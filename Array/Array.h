#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//#define EMPTY_ARRAY(self) Array self = {.type = UNKOWN,.size = 0, .length = 0}
#define DATA_TYPE_STR(dataType)                               \
    (INT == dataType ? "int" : (FLOAT == dataType ? "float" : \
    (CHAR == dataType ? "char" : (DOUBLE == dataType ? "double" : "unknown"))))
//generic swap for any type using memcpy copyright https://stackoverflow.com/questions/3982348/implement-generic-swap-macro-in-c
#define swap(x, y)                                                                    \
    do                                                                                \
        {                                                                             \
            unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
            memcpy(swap_temp, &y, sizeof(x));                                         \
            memcpy(&y, &x, sizeof(x));                                                \
            memcpy(&x, swap_temp, sizeof(x));                                         \
        }                                                                             \
    while (0)

#define median(x, y) (x + y) / 2;

#define GROWTH_RATE  1.5

typedef enum t_dataType
{
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    UNKOWN
}DataType;
//Value converter between data typesdsa
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
    // Candidate candidate;
    union
    {
        int *iPtr;
        float *fPtr;
        char *cPtr;
        double *dPtr;
    };
    int capacity;
    int constant;
    int length;
    double resizeCount;
} Array;
/**
 * Constructor for Array
 * */
// #define newArray(capacity,T)  _newArray(capacity,T);
Array newArray(int capacity,DataType type)
{
    Array newArr;
    newArr.capacity = capacity;
    newArr.constant = capacity;
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
    case DOUBLE:
        newArr.dPtr = (double *)malloc(capacity * sizeof(double));
    default:
        break;
    }
    return newArr; 
}
void _resize(Array *self){
    self->resizeCount++;
    double multiplier = pow(GROWTH_RATE, self->resizeCount);
    self->capacity = multiplier*self->constant;
    switch (self->type)
    {
    case INT:
        self->iPtr = realloc(self->iPtr, self->capacity * sizeof(int));
        break;
    case FLOAT:
        self->fPtr = realloc(self->fPtr, self->capacity * sizeof(float));
        break;
    case CHAR:
        self->cPtr = realloc(self->cPtr,self->capacity * sizeof(char));
        break;
    case DOUBLE:
        self->dPtr = realloc(self->dPtr, self->capacity * sizeof(double));
        break;
    default:
        break;
    }
}
/**
 * generates random values in array
 * */
void randomizeArray(Array *self, unsigned int seed);

/* prints values in an array*/
void displayArray(Array *self);

void destructArray(Array *self);

#define appendToArray(self, value) ( {_appendToArray(self,&value); });
static void _appendToArray(Array *self, void *value);
// static void _setcandidate(array *self, void *value)
// {
//     self->candidate.voidtype = value;
// }

#define insertToArray(self, index, value) ({ _insertToArray(self, index, &value); });
static void _insertToArray(Array *self, int index,void* value);
void _setArrayIndex(Array *self,int index,void* value);

void removeFromArray(Array *self, int index);

#define linearSearch(self, value) _linearSearch(self, &value)
static int _linearSearch(Array *self, void *value);

/*for sorted arrays*/
#define binarySearch(self, value) _binarySearch(self, &value)
static int _binarySearch(Array *self, void *value);

#define Get(self, index)\
    ((self)->length > index ?                       \
    ((self)->type == INT ? (self)->iPtr[index] : \
    ((self)->type == FLOAT ? (self)->fPtr[index]:\
    ((self)->type == CHAR ? (self)->cPtr[index]:\
    ((self)->type == DOUBLE ? (self)->dPtr[index]: 0\
    )))):0)

static void* _get(Array *self,int index){
    if(index>self->length)
        return NULL;
    switch (self->type)
    {
    case INT:
        return &(self->iPtr[index]);
    case FLOAT:
        return &(self->fPtr[index]);
    case CHAR:
        return &(self->cPtr[index]);
    case DOUBLE:
        return &(self->dPtr[index]);
    default:
        break;
    }
}

/* #define my_function(x, y) ({             
    int __err = 0;                       \
    do                                   \
    {                                    \
        __err = function(x, y);          \
        switch (__err)                   \
        {                                \
        case ERROR:                      \
            fprintf(stderr, "Error!\n"); \
            break;                       \
        }                                \
    } while (0);                         \
    __err;                               \
}) */