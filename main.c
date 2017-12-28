/* This code was written by Dimis Savva, teaching assistant for the course */
/* Data Structures and Programming Techniques */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTableInterface.h"
#include "menu.h"

#define INPUT_FILE 1    //define statements
#define INSERT 2
#define SEARCH 3
#define STATISTICS_TOTAL_COLLISIONS 4
#define STATISTICS_MAX_COLLISIONS 5
#define STATISTICS_MIN_COLLISIONS 6
#define SEARCH_FROM_FILE 7
#define PRINT 8
#define DELETE 9
#define QUIT 0


int main(void)
{
      /* variable table for the hash table */
     
     Table table;
     InfoType info;

     int pos,collisions;

     KeyType key;

     table=malloc(TABLESIZE*sizeof(TableEntry));

     Initialize(table);

      int choice;
      char user_filename[100];

      choice = menu();   // get user's first selection

      while(choice != QUIT)   //execute so long as choice is not equal to QUIT
      {
          switch(choice)
              {
                  case INPUT_FILE:
                      menu_get_input_file(user_filename);
                      printf("INFO: The provided filename is %s\n", user_filename);
                      menu_insert_from_file(user_filename,table);
                      break;
                  case INSERT:
                      pos=menu_insert(table);
                      if (pos==-1)
                        printf("INFO: Error in insertion, maybe HashTable is full..\n");
                      else
                        printf("INFO: Key inserted at position %d\n", pos);
                      break;
                  case SEARCH:
                      pos=menu_search(table);
                      if (pos==-1)
                        printf("INFO: Key not found\n");
                      else
                        printf("INFO: Key found at position %d\n", pos);
                      break;
                  case STATISTICS_TOTAL_COLLISIONS:
                      collisions=menu_statistics_total_collisions(table);
                      printf("INFO: Total collisions: %d\n",collisions);
                      break;
                  case STATISTICS_MAX_COLLISIONS:
                      collisions=menu_statistics_max_collisions(table,&pos);
                      printf("INFO: Max collisions: %d, position: %d\n",collisions,pos);
                      break;
                  case STATISTICS_MIN_COLLISIONS:
                      collisions=menu_statistics_max_collisions(table,&pos);
                      printf("INFO: Min collisions: %d, position: %d\n",collisions,pos);
                      break;
                  case SEARCH_FROM_FILE:
                    menu_get_input_file(user_filename);
                    printf("INFO: The provided filename is %s\n", user_filename);
                    menu_search_from_file(user_filename,table);
                    break;
                  case PRINT:
                      menu_print(table);
                      break;
                  case DELETE:
                      menu_delete(table);
                      break;
                  default:    printf("INFO: Bad input.\n");
                              printf("INFO: Please try again..\n");
              }
        choice = menu(); /* get user's subsequent selections */
     }
     /* exit, destroy structures */
     menu_quit(table);
}
