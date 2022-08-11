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

/**
 * @brief Cria uma Lista Circular Vazia
 * 
 * @param cl Endereço da lista (&cl)
 */
void CList_CreateCircularList(CList *cl);

/**
 * @brief Cria um nó.
 * 
 * @param val Valor do nó.
 */
CNode *CList_CreateCNode(int val);

/**
 * @brief Para saber se a lista está ou não vazia.
 * 
 * @param cl Endereço da lista (&cl).
 * @return true Lista vazia.
 * @return false Lista não vazia.
 */
bool CList_isEmpty(CList *cl);

/**
 * @brief Desaloca Lista
 * 
 * @param cl Endereço da lista (&cl).
 */
void CList_DestroyList(CList *cl);

#endif