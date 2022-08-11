#ifndef CLIST_H
#define CLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct CircularNode{

    int val;
    struct CircularNode *prox, *ant;

}CNode;

typedef struct TypeCircularList{

    size_t size;
    CNode *first,*last;

}CList;

#endif