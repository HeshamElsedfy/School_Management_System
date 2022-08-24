#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "School.h"
int i=1;
void insertNode( TreeNodePtr *treePtr, Student* value ){
	 if ( *treePtr == NULL ) {//if the tree is empty
		 *treePtr =(TreeNode*) malloc( sizeof( TreeNode ) );
		 if ( *treePtr != NULL ) {
			 ( *treePtr )->data = value;
			 ( *treePtr )->leftPtr = NULL;
			 ( *treePtr )->rightPtr = NULL;
		 }
		 else {
		     printf( "%d not inserted. No memory available.\n", value );
		 }
	 }
	 else { //the tree is not empty
		if ( value->CS_Score > (*treePtr)->data->CS_Score ) {
			insertNode( &( ( *treePtr )->leftPtr ), value );//put the value in the left branch
		}
		else if ( value->CS_Score <= (*treePtr)->data->CS_Score ) {
			insertNode( &( ( *treePtr )->rightPtr ), value );//put the value in the right branch
		}
 		}
 	}
 void inOrder( TreeNodePtr treePtr ) {//left root right

	if ( treePtr != NULL ) {
	inOrder( treePtr->leftPtr );//print left branch first
    printf("student No.%d is %s with ID %d and CS Score %d percent \n",i,treePtr->data->Name,treePtr->data->ID,treePtr->data->CS_Score);
	i++;
	inOrder( treePtr->rightPtr );//print right branch
	}
}
