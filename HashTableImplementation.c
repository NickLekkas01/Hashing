/* This code is from the book "Data Structures, Algorithms and Software Principles in C" */
/* by Thomas A. Standish */

/* This is the file HashTableImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include "HashTableInterface.h"

int tablesize=TABLESIZE;

int h(KeyType K)
{
  return K % tablesize;
}


/* Hash function good for strings
int h(KeyType K)
{
  int h=0, a=127;
  for (; *K!='\0'; K++)
    h=(a*h + *K) % tablesize;
  return h;
}

*/

int p(KeyType K)
{
  return 1;
}

void Initialize(Table T) {
   int i;

   for (i=0; i<tablesize; i++)
   {
      T[i].Key=EmptyKey;
      T[i].Available=TRUE;
   }
}

int HashInsert(Table T, KeyType K, InfoType I) {
   int i;
   int ProbeDecrement;

   i=h(K);
   ProbeDecrement=p(K);

   while (/*T[i].Key != EmptyKey &&*/ T[i].Available==FALSE){
      i-=ProbeDecrement;
      if (i<0)
        i+=tablesize;
    }
    T[i].Key=K;
    T[i].Info=I;
    T[i].Available=FALSE;
    return i;
}


int HashSearch(Table T, KeyType K) {
   int i;
   int ProbeDecrement;
   KeyType ProbeKey;

   /*Initializations */
   i=h(K);
   ProbeDecrement=p(K);
   ProbeKey=T[i].Key;

   /* Search loop */
   while ((K!=ProbeKey) && (ProbeKey!=EmptyKey)){
      i-=ProbeDecrement;
      if (i<0)
         i+=tablesize;
      ProbeKey=T[i].Key;
   }

   /* Determine success or failure */
   if (ProbeKey==EmptyKey)
      return -1;
   else
      return i;

}

Table Delete(Table T, KeyType K)
{
   Table Table2;
   int i;
   int ProbeDecrement;
   KeyType ProbeKey;

   /*Initializations */
   i=h(K);
   ProbeDecrement=p(K);
   ProbeKey=T[i].Key;

   /* Search loop */
   while ((K!=ProbeKey) && (ProbeKey!=EmptyKey)){
      i-=ProbeDecrement;
      if (i<0)
         i+=tablesize;
      ProbeKey=T[i].Key;
   }
   T[i].Available=TRUE;
   T[i].Key=0;
   
   /* Determine success or failure */
   if (ProbeKey==EmptyKey)
      printf("Key not found\n");
   else
      printf("Key deleted properly \n");

  int counter=0;
  for(i=0 ; i<tablesize ; i++)
  {
      if(T[i].Available==FALSE)
          counter++;            //count the numbers of the table
  }
  if(counter<=(1/8)*tablesize)    //if the table is 1/8 full or 7/8 empty
  {
       KeyType *TempArrayKey;
       TempArrayKey=malloc(tablesize*sizeof(KeyType));
       InfoType *TempArrayInfo;
       TempArrayInfo=malloc(tablesize*sizeof(InfoType));
       int a=0;
       for(i=0 ; i<tablesize ; i++)
       {
          if(T[i].Available==FALSE)
          {
              TempArrayKey[a]=T[i].Key;       //save the numbers into a new table
              TempArrayInfo[a++]=T[i].Info;   //save the info into a new table
          }
       }
       Table2=malloc((tablesize/2)*sizeof(TableEntry));   //Create a New Table with size half of the size of the Previous Table
       Initialize(Table2);                                //Initialize the new table
       int number;
       for(i=0 ; i<a ; i++)
       {
           number=HashInsert(Table2,TempArrayKey[i],TempArrayInfo[i]);    //Insert the numbers to the new Table using the TempArrays
           printf("%d inserted correctly \n",number);
       }
  }
  return Table2;                                                          //Return the new table
}

void Print(Table T){
  int i;
  for(i=0;i<tablesize;++i){
      if(T[i].Available == TRUE){
        printf("Empty element in position %d\n", i);
      }else{
        printf("Element in position %d with key \"%d\"\n",i,T[i].Key);
      }
    }
}
