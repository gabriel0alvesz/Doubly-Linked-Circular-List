#include "clist.h"

void CList_CreateCircularList(CList *cl){

    cl->first = (CNode*)(malloc(sizeof(CNode))); // Cria o nó que é a cabeça da lista

    cl->first->prox = NULL;
    cl->last = cl->first;
    cl->size = 0;
    //Lista circular vazia criada!
}   

CNode *CList_CreateCNode(int val){

    CNode *new = (CNode*)malloc(sizeof(CNode));

    new->ant = NULL;
    new->prox = NULL;
    new->val = val;
    //Nó criado!

    return new;
}

bool CList_isEmpty(CList *cl){

    return cl->size == 0 || cl->last == cl->first;
}

void CList_DestroyList(CList *cl){
    
    if(!CList_isEmpty(cl)){
        
        CNode *pos = cl->first->prox;
        CNode *aux = NULL;

        while(pos != NULL){

            aux = pos;
            pos = pos->prox;
            free(aux);
        }

        free(pos);
        free(cl);

        cl = NULL;
        //Lista desalocada!
    }else{

        cl = NULL;
    }
    
}
