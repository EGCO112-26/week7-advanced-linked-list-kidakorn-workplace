// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
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
   scanf( "%u", &choice );

   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter ID: " );
            scanf( "%d", &id );
            printf( "%s", "Enter Name: " );
            scanf( "%s", name );
            
            insert( &startPtr, id, name ); 
            printList( startPtr );
            break;

         case 2:
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter ID to be deleted: " );
               scanf( "%d", &id );

               if ( deletes( &startPtr, id ) != -1 ) { 
                  printf( "ID %d deleted.\n", id );
                  printList( startPtr );
               } 
               else {
                  printf( "ID %d not found.\n\n", id );
               } 
            } 
            else {
               puts( "List is empty.\n" );
            } 
            break;

         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while

   if ( !isEmpty( startPtr ) ) {
       printf("\nCleaning up remaining nodes...\n");
       while ( startPtr != NULL ) {
           LLPtr tempPtr = startPtr;
           printf("Freeing ID: %d (%s)\n", startPtr->id, startPtr->name);
           startPtr = startPtr->nextPtr; 
           free( tempPtr ); 
       }
   }

   puts( "End of run." );
   return 0;
}