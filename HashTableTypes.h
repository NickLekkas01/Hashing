#ifndef __HASHTABLETYPES__
#define __HASHTABLETYPES__
/* This is the file HashTableTypes.h */

#define TABLESIZE 997   /* 997 is prime */

#define EmptyKey 0

typedef enum {FALSE, TRUE} Boolean;

typedef int KeyType;
typedef struct {
           int first;
           int second;   /* two dummy information fields */
        } InfoType;
typedef struct {
           KeyType Key;
           InfoType Info;
           Boolean Available;
         } TableEntry;
typedef TableEntry *Table;

#endif
