#include "readfile.h"


void score_read(Student *stu){
    //必須為ANSL編碼
    char file_name[] = "TestRecords100.csv";
    FILE* score_file;
    score_file = fopen(file_name, "r");
    if(!score_file){
        printf("Fail to read file %s", file_name);
        return;
    }
    char str[50];
    char *token;
    //先讀取第一行的科目
    fgets(str, 50, score_file);
    token = strtok(str, ",");
    while(token != NULL){
            printf("%s\t",token);
            token = strtok(NULL, ",");
        }
    printf("\n");
    char ID[10];
    int i=0;
    while(fgets(str, 100, score_file) != NULL){
        token = strtok(str, ",");
        int j = 0;
        while(token != NULL){
            switch(j){
                case 0:
                    sscanf(token, "%s", stu[i].ID);
                    break;
                case 1:
                    stu[i].Eng = atof(token);
                    break;
                case 2:
                    stu[i].Math = atof(token);
                    break;
                case 3:
                    stu[i].Sci = atof(token);
                    break;
            }
            //printf("%s\t",token);
            token = strtok(NULL, ",");
            j++;
        }
        //printf("test\n");
        i++;
    }
    fclose(score_file);
    free(token);
}

int get_data_size(){
    char file_name[] = "TestRecords100.csv";
    FILE* score_file;
    score_file = fopen(file_name, "r");
    if(!score_file){
        printf("Fail to read file %s", file_name);
        return 0;
    }
    char str[100];
    char *token;
    int i = 0;
    while(fgets(str, 100, score_file) != NULL){
        i++;
        token = strtok(str, ",");
        while(token != NULL){
            token = strtok(NULL, ",");
        }
        //printf("get_data_size = %d\n",i);
    }
    printf("get_data_size = %d\n",i);
    free(str);
    free(token);
    return i-1;
}

void score_write(char player_name[10], int player_score){
    FILE* score_file;
    int score[10];
    char name[10][10];

    int fscore;
    char fname[10];
    score_file = fopen("TestRecords100.csv", "r");
    int i = 0;
    while(fscanf(score_file, "%s\t%d\n", fname, &fscore) != EOF) {
        score[i] = fscore;
        int j = 0;
        for(j=0;j<10;j++){
            name[i][j] = fname[j];
        }
        //name[i] = fname;
        //printf("%s\t%d\n", fname, fscore);
        i++;
    }
    fclose(score_file);

    score_file = fopen("TestRecords100.csv", "w");

    i = 0;
    while(i<10) {
        if(player_score <= score[i]){
            printf("score = %d",score[i]);
            fprintf(score_file, "%s\t%d\r\n", player_name, player_score);
            player_score = 10000;
        }else
        fprintf(score_file, "%s\t%d\r\n", name[i], score[i]);
        i++;
    }
    fclose(score_file);
}
