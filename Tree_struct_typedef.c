#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {                                        
   struct treeNode *leftPtr;    
   int data;                 
   struct treeNode *rightPtr; 
};                  

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *treePtr, int value );
void preOrder( TreeNodePtr treePtr );

int main() { 
   int i;                      
   int item;                   
   TreeNodePtr rootPtr = NULL; 

   srand( time( NULL ) ); 
	
  for ( i = 1; i <= 10; i++ ) { 
      item = rand() % 15;
      insertNode( &rootPtr, item );
   } 
   preOrder( rootPtr );



   return 0;

} 

void insertNode( TreeNodePtr *treePtr, int value ) { 
   
   if ( *treePtr == NULL ) {   
      *treePtr = malloc( sizeof( TreeNode ) );

      if ( *treePtr != NULL ) { 
         ( *treePtr )->data = value;
         ( *treePtr )->leftPtr = NULL;
         ( *treePtr )->rightPtr = NULL;
      } 
      else {
      } 

   } 

   else { 

    
      if ( value < ( *treePtr )->data ) {                   
         insertNode( &( ( *treePtr )->leftPtr ), value );   
      }                                        

      
      else if ( value > ( *treePtr )->data ) {                 
         insertNode( &( ( *treePtr )->rightPtr ), value );     
      }                                       
      else { 
         
      } 

   } 

} 



void preOrder( TreeNodePtr treePtr ) { 
   
   if ( treePtr != NULL ) {                
      printf( " %d", treePtr->data );      
      preOrder( treePtr->leftPtr );        
      preOrder( treePtr->rightPtr );       
   }             

} 



