#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
   int id;
   char name[50];
   struct Node *nextPtr;
   struct Node *prevPtr;
};

typedef struct Node LLnode;
typedef LLnode *LLPtr;

void insert( LLPtr *sPtr, int id, char name[] );
int deletes( LLPtr *sPtr, int id );
int isEmpty( LLPtr sPtr );
void printList( LLPtr currentPtr );
void instructions( void );

void instructions( void ) {
   printf( "Enter your choice:\n"
           "   1 to insert an element into the list.\n"
           "   2 to delete an element from the list.\n"
           "   3 to end.\n" );
}

void insert( LLPtr *sPtr, int id, char name[] ) {
   LLPtr newPtr = (LLPtr) malloc( sizeof( LLnode ) );
   if ( newPtr != NULL ) {
      newPtr->id = id;
      strcpy(newPtr->name, name);
      newPtr->nextPtr = NULL;
      newPtr->prevPtr = NULL;

      LLPtr previousPtr = NULL;
      LLPtr currentPtr = *sPtr;

      while ( currentPtr != NULL && id > currentPtr->id ) {
         previousPtr = currentPtr;
         currentPtr = currentPtr->nextPtr;
      }

      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = *sPtr;
         if (*sPtr != NULL) (*sPtr)->prevPtr = newPtr;
         *sPtr = newPtr;
      } else { 
         previousPtr->nextPtr = newPtr;
         newPtr->prevPtr = previousPtr;
         newPtr->nextPtr = currentPtr;
         if (currentPtr != NULL) currentPtr->prevPtr = newPtr;
      }
   }
}

int deletes( LLPtr *sPtr, int id ) {
   LLPtr currentPtr = *sPtr;
   while ( currentPtr != NULL && currentPtr->id != id ) {
      currentPtr = currentPtr->nextPtr;
   }
   if ( currentPtr != NULL ) {
      LLPtr tempPtr = currentPtr;
      if ( currentPtr->prevPtr == NULL ) { 
         *sPtr = currentPtr->nextPtr;
         if (*sPtr != NULL) (*sPtr)->prevPtr = NULL;
      } else { 
         currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
         if (currentPtr->nextPtr != NULL) {
            currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
         }
      }
      free( tempPtr );
      return id;
   }
   return -1;
}

int isEmpty( LLPtr sPtr ) {
   return sPtr == NULL;
}

void printList( LLPtr currentPtr ) {
   if ( isEmpty( currentPtr ) ) {
      printf( "List is empty.\n\n" );
   } else {
      LLPtr temp = currentPtr;
      LLPtr lastPtr = NULL;

      while ( temp != NULL ) {
         printf( "%d %s --> ", temp->id, temp->name );
         if (temp->nextPtr == NULL) lastPtr = temp;
         temp = temp->nextPtr;
      }
      printf( "NULL\n" );

      while ( lastPtr != NULL ) {
         printf( "%d %s --> ", lastPtr->id, lastPtr->name );
         lastPtr = lastPtr->prevPtr;
      }
      printf( "NULL\n\n" );
   }
}
#endif