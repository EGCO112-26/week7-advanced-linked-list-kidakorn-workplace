#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

int main( void ) { 
   LLPtr startPtr = NULL;
   unsigned int choice;
   int id;
   char name[50];

   instructions();
   printf( "? " );
   
   while ( scanf( "%u", &choice ) == 1 && choice != 3 ) { 
      switch ( choice ) { 
         case 1:
            scanf( "%d %s", &id, name );
            insert( &startPtr, id, name );
            printf( "The list is:\n" );
            printList( startPtr );
            break;
         case 2:
            if ( !isEmpty( startPtr ) ) { 
               scanf( "%d", &id );
               if ( deletes( &startPtr, id ) != -1 ) { 
                  printf( "ID %d deleted.\n", id );
                  printf( "The list is:\n" );
                  printList( startPtr );
               } else {
                  printf( "ID %d not found.\n", id );
               }
            } else {
               scanf( "%d", &id );
               printf( "List is empty.\n" );
            }
            break;
         default:
            printf( "Invalid choice.\n" );
            instructions();
            break;
      }
      printf( "? " );
   }

   if ( !isEmpty( startPtr ) ) {
      while ( startPtr != NULL ) {
         LLPtr tempPtr = startPtr;
         startPtr = startPtr->nextPtr;
         free( tempPtr );
      }
   }

   printf( "End of run.\n" );
   return 0;
}