#include "stdafx.h"
#include "test1.h"
struct student st[maxst];
int totalStudent=0;
int find(int tmp)
{
    int i=0;
    for(i=0;i<totalStudent;i++)
        if(st[i].SID==tmp)
            return 1;
    return 0;
}
void printtable()
{
    int i=0;
    int j=0;
    printf("------------Student-----------\n");
    for(;i<totalStudent;i++)
    {
        printf("%10d\t%20d\t%10s\t",st[i].SID,st[i].CID,st[i].name);
        for(j=0;j<4;j++)
        {
            printf("%3d\t",st[i].score[j]);
        }
        printf("\n");
    }
}
void add()
{
   struct student temp;
   int j=0;
   printf("Please enter the SID,CID,name and four scores.Enter 0 to finish.\n");
   scanf("%d",&temp.SID);
   if(find(temp.SID))
    {
        printf("Duplicated Student.\n");
        return;
    }
     printf("Please enter CID,name and four scores.Enter 0 to finish.\n");
     scanf("%d",&temp.CID);
     printf("Please enter name and four scores.Enter 0 to finish.\n");
     scanf("%s",temp.name);
     printf("Please enter four scores.Enter 0 to finish.\n");
     for(;j<4;j++)
     {
        scanf("%d",&temp.score[j]);
     }
	 st[totalStudent] = temp;
	 totalStudent++;
     printtable();
}
void DQ(int a)
{
	char input[10];
		for (;;)
		{
			printf("Please enter SID or name. Enter 0 to finish.");
			scanf("%s", input);
		}
}
void stat()
{

}
void Welcome()
{
    char str1[] = "Welcome to Student Performance Management System (SPMS).\n";
    printf(str1);
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n");
}
void Serve()
{
    int choice;
   for(;;)
   {
        Welcome();
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:return;
            case 1:add();break;
            case 2:DQ(1);break;
            case 3:DQ(0);break;
            case 4:printf("That hurts sutdents' heart. You can't do that.\n");break;
            case 5:stat();break;
            default:printf("Please enter a valid command.\n");
        }
   }
}