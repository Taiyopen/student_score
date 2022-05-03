#include "main.h"
#include "readfile.h"
#include "array.h"
#include "function.h"

int main()
{
    int total = get_data_size();
    Student *stu = create_data1D(total);
    printf("score_read ...\n");
    score_read(stu);
    print_data(stu, total);
    return 0;
}
