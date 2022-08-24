#ifndef SCHOOL_H
#define SCHOOL_H
#define ENABLE 1
#define DISABLE 0
#define ENABLE_DEBUGGING DISABLE
#include<stdbool.h>
typedef struct student{
int ID;
int CS_Score;
char* Name;
char* PhoneNo;
char* Birth_Date;
}Student;
typedef struct Node{
    Student data;
    struct Node*pPrev;
    struct Node*pNext;
}ListNode;

typedef struct myList{
    ListNode *phead;
    ListNode *ptail;
    int listSize;
}List;
void Create_School(List * pl);
void New_Student_ID(List * pl);
void New_Student_Name(List * pl);
void Student_List(List * pl);
bool isEmpty(List * pl);
void Delete_Student(List *pl,int id);
void Student_Edit(List *pl,int id);
int List_Size(List * pl);
void Student_Score(List *pl);
void Rank_Student(List *pl);
#endif
