#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct Student{
    char ID[10];
    double Eng;
    double Math;
    double Sci;

} Student;

void score_read(Student *res);
int get_data_size();

#endif
