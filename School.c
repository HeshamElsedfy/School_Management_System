#include<stdio.h>
#include"School.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "Tree.h"
#define printf __mingw_printf
#define NAME 1
#define Id 2
#define BIRTH_DATE 3
#define CS_SCORE 4
#define PHONE_NUMBER 5
#define EXIT 6
#define NAMESIZE 30
#define PHONENOSIZE 15
#define BDSIZE 10
extern int i;
void Create_School(List * pl){
    pl->phead = NULL;
    pl->ptail = NULL;
    pl->listSize = 0;
}
void New_Student_ID(List * pl){
bool uniqueflg;
ListNode * temp = pl->phead;//init
ListNode* pn =(ListNode*)malloc(sizeof(ListNode));
pn->data.Birth_Date=(char*)malloc(BDSIZE);
pn->data.Name=(char*)malloc(NAMESIZE);
pn->data.PhoneNo=(char*)malloc(PHONENOSIZE);
printf("Please enter student ID\n");
//checking if the student Id is not duplicate
do{
uniqueflg=1;
fflush(stdin);
scanf("%d",&pn->data.ID);
temp = pl->phead;
for(int i=0;i<List_Size(pl);i++){
if(temp->data.ID==pn->data.ID){

    uniqueflg=0;
    break;
}
temp=temp->pNext;
}
if(uniqueflg==0)
    printf("this id is taken, please enter a unique id\n");
else
    break;
}
while(!uniqueflg);
///////////
printf("Please enter student Name\n");
fflush(stdin);
gets(pn->data.Name);
 #if(ENABLE_DEBUGGING==1)
    printf("i'm out of gets\n");
    printf("Name is: %s\n",pn->data.Name);
 #endif
printf("Please enter student Birth Date\n");
fflush(stdin);
gets(pn->data.Birth_Date);
 #if(ENABLE_DEBUGGING==1)
    printf("i'm out of gets\n");
    printf("birth date is: %s\n",pn->data.Birth_Date);
 #endif
printf("Please enter student CS score\n");
scanf("%d",&pn->data.CS_Score);
printf("Please enter student Phone Number\n");
fflush(stdin);
gets(pn->data.PhoneNo);
 #if(ENABLE_DEBUGGING==1)
    printf("i'm out of gets\n");
    printf("Phone No. is %s\n",pn->data.PhoneNo);
 #endif
 int len=strlen(pn->data.Name);
 if(pn == NULL)
 {
     printf("Heap is Full\n");
     return;
 }
 //step 2: Initialize Node
 pn->pPrev =NULL;
 pn->pNext = NULL;

 //step 3 : Insert Node in List
 pl->listSize++;
 if(isEmpty(pl)){ // List is Empty
     pl->phead = pn;
     pl->ptail = pn;
 }
 else{  // List is Not Empty
     temp = pl->phead;//init
     while(temp != NULL && temp->data.ID<pn->data.ID){// compare new node's id with the current nodes id's
        temp = temp->pNext;
     }
     if(temp == pl->phead ){// Insert at head
         pn->pNext = pl->phead; // assign old head as new node next
         pl->phead->pPrev = pn; //  assign new node as old head prev
         pl->phead = pn;
         pn->pPrev=NULL;
     }
     else if(temp == NULL){//Insert at tail
         pn->pPrev = pl->ptail;
         pl->ptail->pNext = pn;
         pl->ptail = pn;
         pn->pNext=NULL;
     }
     else{
       pn->pNext = temp;
       pn->pPrev = temp->pPrev ;
       temp->pPrev->pNext  = pn;
       temp ->pPrev = pn;

     }

 }
 #if(ENABLE_DEBUGGING == 1)
    printf("%d is inserted\n",pn->data.ID);
 #endif
}
void New_Student_Name(List * pl){
ListNode * temp = pl->phead;
int uniqueflg;
ListNode* pn =(ListNode*)malloc(sizeof(ListNode));
pn->data.Birth_Date=(char*)malloc(BDSIZE);
pn->data.Name=(char*)malloc(NAMESIZE);
pn->data.PhoneNo=(char*)malloc(PHONENOSIZE);
printf("Please enter student ID\n");
//checking if the new student id is not duplicate
do{
uniqueflg=1;
fflush(stdin);
scanf("%d",&pn->data.ID);
temp = pl->phead;
for(int i=0;i<List_Size(pl);i++){
if(temp->data.ID==pn->data.ID){

    uniqueflg=0;
    break;
}
temp=temp->pNext;
}
if(uniqueflg==0)
    printf("this id is taken, please enter a unique id\n");
else
    break;
}
while(!uniqueflg);
temp = pl->phead;
///////////
printf("Please enter student Name\n");
fflush(stdin);
gets(pn->data.Name);
 #if(ENABLE_DEBUGGING==1)
    printf("i'm out of gets\n");
    printf("Name is: %s\n",pn->data.Name);
 #endif
printf("Please enter student Birth Date\n");
fflush(stdin);
gets(pn->data.Birth_Date);
 #if(ENABLE_DEBUGGING==1)
    printf("i'm out of gets\n");
    printf("birth date is: %s\n",pn->data.Birth_Date);
 #endif
printf("Please enter student CS score\n");
scanf("%d",&pn->data.CS_Score);
printf("Please enter student Phone Number\n");
fflush(stdin);
gets(pn->data.PhoneNo);
 #if(ENABLE_DEBUGGING==1)
    printf("i'm out of gets\n");
    printf("Phone No. is %s\n",pn->data.PhoneNo);
 #endif
 int len=strlen(pn->data.Name);
 if(pn == NULL)
 {
     printf("Heap is Full\n");
     return;
 }
 //step 2: Initialize Node
 pn->pPrev =NULL;
 pn->pNext = NULL;

 //step 3 : Insert Node in List
 pl->listSize++;
 if(isEmpty(pl)){ // List is Empty
     pl->phead = pn;
     pl->ptail = pn;
 }
 else{  // List is Not Empty

    ListNode * temp = pl->phead;//init
     while(temp != NULL && (strcmp(pn->data.Name,temp->data.Name)==1))// condition
     {
        temp = temp->pNext;
     }
     if(temp == pl->phead )// Insert at head
     {
         pn->pNext = pl->phead; //step 1 : assign old head as new node next
         pl->phead->pPrev = pn; // step 2: assign new node as old head prev
         pl->phead = pn;
         pn->pPrev=NULL;
 //step 3: update head
     }
     else if(temp == NULL)//Insert at tail
     {
         pn->pPrev = pl->ptail;//step 1
         pl->ptail->pNext = pn;//step 2
         pl->ptail = pn; //step 3
         pn->pNext=NULL;
     }
     else //insert at any where else ( at middle )
     {
       pn->pNext = temp; //step 1
       pn->pPrev = temp->pPrev ;// step 2
       temp->pPrev->pNext  = pn;//step 3 // pn->pPrev->pNext = pn
       temp ->pPrev = pn;//step 4

     }

 }
 #if(ENABLE_DEBUGGING == 1)
    printf("%d is inserted\n",pn->data.ID);
 #endif
}
void Student_List(List * pl){
    int i=1;
    if(isEmpty(pl))
    {
        printf("List is Empty\n");
        return;
    }
    ListNode *temp;
    printf("\n------------------------------------\n");
    printf("Name\t\tID\t\tBirth Date\t\tPhone Number\t\t CS score\n");
    printf("\n------------------------------------\n");
    for(temp = pl->phead;temp!= NULL;temp = temp->pNext)
    {
        printf("%s\t%d\t\t%s\t\t%s\t\t%d\n",temp->data.Name,temp->data.ID,temp->data.Birth_Date,temp->data.PhoneNo,temp->data.CS_Score);
        i++;
    }
    printf("\n---------------------------------\n");
}
void Delete_Student(List *pl,int id){
//find node
int i=0;
ListNode *temp=pl->phead;
while (i<List_Size(pl)){
    if(id==temp->data.ID)
    {
        break;
    }
    temp=temp->pNext;
    i++;
}
if(i>=List_Size(pl)){
    printf("ID not found\n");
    return;
}
else if(i==0){
    temp=pl->phead;
    free(pl->phead);
    temp->pNext->pPrev=NULL;
    pl->phead=temp->pNext;
}
else if(i==List_Size(pl)-1){
    temp=pl->ptail;
    free(pl->ptail);
    temp->pPrev->pNext=NULL;
    pl->ptail=temp->pPrev;
}
else{
    temp->pNext->pPrev=temp->pPrev;
    temp->pPrev->pNext=temp->pNext;
    free(temp);
}

pl->listSize--;
}
int List_Size(List * pl){
     return pl->listSize;
}
void Student_Edit(List *pl,int id){
//find student
int i=0;
ListNode *temp=pl->phead;
while (i<List_Size(pl)){
    if(id==temp->data.ID)
    {
        #if(ENABLE_DEBUGGING==1)
        printf("id found\n");
        #endif
        break;
    }
    temp=temp->pNext;
    i++;
}
if(i>=List_Size(pl)){
    printf("ID Not Found\n");
    return;
}
int choice;
//display secondary menu
do{
printf("please enter the choice of data to edit\n");
printf("\n------------------------------------\n");
printf("1-Name\n2-ID\n3-Birth Date\n4-cs Score\n5-Phone Number\n6-Exit\n");
printf("------------------------------------\n");
fflush(stdin);
scanf("%d",&choice);
switch(choice){
case NAME:
    printf("please enter the new Name\n");
    fflush(stdin);
    gets(temp->data.Name);
    break;
case Id:
    printf("please enter the new ID\n");
    fflush(stdin);
    scanf("%d",&temp->data.ID);
    break;
case BIRTH_DATE:
    printf("please enter the new birth date\n");
    fflush(stdin);
    gets(temp->data.Birth_Date);
    break;
case CS_SCORE:
    printf("please enter the new CS Score\n");
    fflush(stdin);
    scanf("%d",&temp->data.CS_Score);
    break;
case PHONE_NUMBER:
    printf("please enter the new phone number\n");
    fflush(stdin);
    gets(temp->data.PhoneNo);
    break;
case EXIT:
    break;
default:
    printf("Wrong Choice\n");
}
}
while(choice!=EXIT);
}
void Student_Score(List *pl){
ListNode *temp=pl->phead;
int i=0;
while (temp!=NULL){
printf("please enter CS score for student with code %d and name %s\n",temp->data.ID,temp->data.Name);
fflush(stdin);
scanf("%d",&temp->data.CS_Score);
#if(ENABLE_DEBUGGING==1)
printf("i'm out of scanf");
#endif
temp=temp->pNext;

}
}
bool isEmpty(List * pl){
    return (pl->phead == NULL);
}
void Rank_Student(List *pl){
i=1;
ListNode *temp=pl->phead;
TreeNodePtr rootPtr = NULL;
while(temp!=NULL){
    insertNode(&rootPtr,&temp->data);
    temp=temp->pNext;
}
temp=pl->phead;
inOrder(rootPtr);
}

