#ifndef __HASHTABLEINTERFACE__
#define __HASHTABLEINTERFACE__

/* This is the file HashTableInterface.h */
#include "HashTableTypes.h"

int h(KeyType);
int p(KeyType);

void Initialize(Table);
int Empty(Table);
int Full(Table);
int HashInsert(Table, KeyType, InfoType);
int HashSearch(Table, KeyType);
void Print(Table);
Table Delete(Table T, KeyType K);
#endif
