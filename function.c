#include "function.h"

void print_data(Student *stu, int total){
    int i;
    for(i = 0;i<total;i++){
        printf("%s\t%.3f\t%.3f\t%.3f\n", stu[i].ID, stu[i].Eng, stu[i].Math, stu[i].Sci);
    }
}
