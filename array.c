#include "readfile.h"
#include "array.h"

Student *create_data1D(int size){
    int i, j;
    Student *yee;
    yee = (Student*)calloc(size,sizeof(Student));
    return yee;
}

