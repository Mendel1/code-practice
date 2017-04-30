#ifndef TEST1_H
#define TEST1_H
#include <stdio.h>
#define maxst 100
struct student;
struct student
{
    int SID;
    int CID;
    char name[10];
    int score[4];
};
void Welcome();
void Serve();
#endif