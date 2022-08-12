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

    new->ant = new;
    new->prox = new;
    new->val = val;
    //Nó criado!

    return new;
}

bool CList_isEmpty(CList *cl){

    return cl->size == 0 || cl->last == cl->first;
}

void CList_InsertInHead(CList *cl, int val){

    CNode *new = CList_CreateCNode(val);

    if(CList_isEmpty(cl)){

        cl->first->prox = new;
        cl->last = new;
    }else{

        // Inserçao normal
        new->prox = cl->first->prox; // Novo nó aponta para o antigo 1o nó
        cl->first->prox->ant = new; // O novo segundo nó tera seu ponteiro anterior apontando para o antigo nó
        cl->first->prox = new; // A cabeça agora aponta para o novo 1o nó

        //Fatualizando ponteiros para lista circular
        new->ant = cl->last; // O novo primeiro elemento tem seu anterior, como o ultimo elemento da lista
        cl->last->prox = new; // o ponteiro de ultimo tera o seu prox apontando para o primeiro elemento da lista.

    }

    cl->size++;

}

void CList_PrintCList(CList *cl){

    if(!CList_isEmpty(cl)){
        CNode *p = cl->first->prox;

        do{

            printf("%d ", p->val);
            p = p->prox;

        }while(p != cl->first->prox);

        printf("[%lu]\n", cl->size);
    
    }else{

        puts("---> Lista Vazia!\n\n");
        
    }

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
