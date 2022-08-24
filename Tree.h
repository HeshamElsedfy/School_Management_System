#ifndef _TREE_H_
#define _TREE_H_
#include "School.h"
typedef struct treeNode {
    struct treeNode *leftPtr; //pinter to the left node
    Student* data; //pointer to a struct student data type
    struct treeNode *rightPtr; //pointer to the right node
}TreeNode;
 typedef TreeNode* TreeNodePtr;

 void insertNode( TreeNodePtr *treePtr, Student* value  ); // change
 void inOrder( TreeNodePtr treePtr );
#endif
