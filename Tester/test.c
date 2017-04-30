/*
test.c
author:mendel
*/
#include <stdio.h>
#include <time.h>
#include "test1.h"
#define UINT unsigned int

int main()
{
    int starttime=0;
    int endtime=0;
    starttime=clock();
    Serve();
    endtime=clock();
    printf("excute time is %d ms.",endtime-starttime);
    getchar();
    return 0;
}