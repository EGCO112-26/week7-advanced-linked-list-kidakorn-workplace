#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h" 

int main( void )
{ 
   LLPtr startPtr = NULL; 
   unsigned int choice; 
   int id; 
   char name[50];

   instructions(); 
   printf( "%s", "? " );
   
   while ( scanf("%u", &choice) != EOF && choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            
            if (scanf("%d %s", &id, name) == 2) {
               insert( &startPtr, id, name );
               printList( startPtr );
            }
            break;

         case 2:
            if ( !isEmpty( startPtr ) ) { 
               if (scanf("%d", &id) == 1) {
                  if ( deletes( &startPtr, id ) != -1 ) { 
                     printf( "ID %d deleted.\n", id );
                     printList( startPtr );
                  } 
                  else {
                     printf( "ID %d not found.\n\n", id );
                  }
               }
            } 
            else {
             
               scanf("%d", &id); 
               puts( "List is empty.\n" );
            } 
            break;

         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } 

      printf( "%s", "? " );
   } 

   if ( !isEmpty( startPtr ) ) {
       while ( startPtr != NULL ) {
           LLPtr tempPtr = startPtr;
           startPtr = startPtr->nextPtr;
           free( tempPtr );
       }
   }

   puts( "End of run." );
   return 0;
}