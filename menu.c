/* This code was written by Dimis Savva, teaching assistant for the course */
/* Data Structures and Programming Techniques */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HashTableTypes.h"
#include "HashTableInterface.h"

int menu_get_input_file(char * user_filename)
{
  printf("Q: Enter the filename of the input file:\n");
  scanf("%s", user_filename);
  return 0;
}

int menu_search(Table table)
{
  KeyType key;
  InfoType info;
  printf("Q: Enter the key:\n");
  scanf("%d", & key);
  int pos = HashSearch(table, key);

  return pos;
}

int menu_insert(Table table)
{
  KeyType key;
  InfoType info;

  printf("Q: Enter the key:\n");
  scanf("%d", & key);
  printf("Q: Enter the first value:\n");
  scanf("%d", & info.first);
  printf("Q: Enter the second value:\n");
  scanf("%d", & info.second);


  int pos = HashInsert(table,key,info);
  return pos;
}

int menu_statistics_total_collisions(Table table)
{
  //You have to implement this function, you should also implement the related functionality for HashTable
  //It should return the total collisions measured in HashTable
  printf("ERROR: Please, implement this function...\n");
  return -1;
}

int menu_statistics_max_collisions(Table table,int * position)
{
  //You have to implement this function, you should also implement the related functionality for HashTable
  //Parameter pos should return (to the caller function) the position of the bucket with the max collisions
  //The function should return the max collisions
  printf("ERROR: Please, implement this function...\n");
  *position = -1;
  return -1;
}

int menu_statistics_min_collisions(Table table,int * position)
{
  //You have to implement this function, you should also implement the related functionality for HashTable
  //Parameter pos should return (to the caller function) the position of the bucket with the max collisions
  //The function should return the max collisions
  printf("ERROR: Please, implement this function...\n");
  *position = -1;
  return -1;
}


void menu_insert_from_file(char * user_filename,Table table){
  /* assumes no word exceeds length of 1023 */
  FILE *file=fopen(user_filename, "r");
  if (!file){
    printf("ERROR: Error opening file..\n");
    return;
  }
  int x;
  while (fscanf(file, " %ds", &x) == 1) {
    //printf("Just read '%d' from file\n", x );
    KeyType key=x;
    InfoType info;
    //info.first=0;
    //info.second=0;
    HashInsert(table,key,info);
  }
  printf("INFO: You have to re-implement this function to store string values in HashTable...\n");
  return;
}

void menu_search_from_file(char * user_filename,Table table){
  /* assumes no word exceeds length of 1023 */
  FILE *file=fopen(user_filename, "r");
  if (!file){
    printf("ERROR: Error opening file..\n");
    return;
  }
  int x;
  while (fscanf(file, " %ds", &x) == 1) {
    //printf("Just read '%d' from file\n", x );
    KeyType key=x;
    InfoType info;
    //info.first=0;
    //info.second=0;

    int pos=HashSearch(table, key);

  }
  return;
}

void menu_print(Table table){
  Print(table);
}

void menu_delete(Table table){
  int k;
  printf("Give me the keytype you want to delete \n");
  scanf("%d",&k);
  
  table=Delete(table,k);
}

void menu_quit()
{
    printf("INFO: Quiting...Bye!\n");
    fflush(stdin);
    exit(0);
}

int menu(void)
{
    int option;

    printf("\n--------------\nHashTable Menu\n--------------\n");
    printf("1.\tEnter name of input file\n");
    printf("2.\tInsert an element to HashTable\n");
    printf("3.\tSearch for an element with key\n");
    printf("4.\tPrint total collisions\n");
    printf("5.\tPrint max collisions\n");
    printf("6.\tPrint min collisions\n");
    printf("7.\tSearch using all words from file, print total search time\n\n");
    printf("8.\tPrint hash table contents\n");
    printf("9.\tDelete\n");
    printf("0.\tQuit\n\n");
    printf("Q: Make your selection: ");

    while( (scanf(" %d", &option) != 1) /* non-numeric input */
          || (option < 0)               /* number too small */
          || (option > 9))              /* number too large */
    {
      fflush(stdin);                    /* clear bad data from buffer */
      printf("INFO: That selection isn't valid. Please try again.\n\n");
      printf("Q: Your choice? ");
    }
    printf("--------------\n");
    return option;
}
