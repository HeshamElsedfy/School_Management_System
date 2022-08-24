#include<stdio.h>
#include"School.h"
#define NEW_STUDENT 1
#define STUDENT_LIST 2
#define DELETE 3
#define EDIT_STUDENT 4
#define STUDENTSCORE 5
#define RANK_STUDENT 6
#define EXIT 7
#define SORT_BY_NAME 1
#define SORT_BY_ID 2
#define printf __mingw_printf
void main_menu(){
int choice;
int sortchoice;
int id;
List l;
Create_School(&l);
do{
printf("\n==============================\n");
printf("please enter choice how do you want to sort students ?\n");
printf("1-Sort by Name\n2-Sort by Id");
printf("\n==============================\n");
scanf("%d",&sortchoice);
if((sortchoice!=1)&&(sortchoice!=2))
    printf("please enter a correct choice 1 or 2");
}
while((sortchoice!=1)&&(sortchoice!=2));
do{
printf("\n==============================\n");
printf("Please Enter choice:\n");
printf("1-Insert Student\n2-Student List\n3-Delete Student\n4-Edit Student\n5-Edit Students Score\n6-Rank Students\n7-Exit");
printf("\n==============================\n");
scanf("%d",&choice);
switch(choice){
case NEW_STUDENT:
    switch(sortchoice){
    case SORT_BY_NAME:
    New_Student_Name(&l);
    break;
    case SORT_BY_ID:
    New_Student_ID(&l);
    break;
    }
break;
case STUDENT_LIST:
Student_List(&l);
break;
case DELETE:
printf("please enter student id to delete\n");
scanf("%d",&id);
Delete_Student(&l,id);
break;
case EDIT_STUDENT:
printf("please enter student id to Edit\n");
scanf("%d",&id);
Student_Edit(&l,id);
break;
case EXIT:
printf("Good bye\n");
break;
case RANK_STUDENT:
Rank_Student(&l);
break;
case STUDENTSCORE:
Student_Score(&l);
break;
default:
printf("wrong choice\n");
}
}
while(choice!=EXIT);
}
void main(){
main_menu();
}
