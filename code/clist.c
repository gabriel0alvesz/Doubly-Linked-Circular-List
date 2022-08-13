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

        //atualizando ponteiros para lista circular
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

    //printf("last->prox = %d\nfirst->prox->ant = %d\n", cl->last->prox->val, cl->first->prox->ant->val);

}

void CList_PrintInvertCList(CList *cl){

    if(!CList_isEmpty(cl)){
        
        CNode *p = cl->last;

        do{

            printf("%d ", p->val);
            p = p->ant;

        }while(p != cl->last);

        printf("[%lu]\n", cl->size);
    
    }else{

        puts("---> Lista Vazia!\n\n");

    }
}

void CList_InsertFinalList(CList *cl, int val){

    CNode *new = CList_CreateCNode(val);

    if(CList_isEmpty(cl)){

        cl->first->prox = new;
        cl->last = new;

    }else{
        
        //Inserçao normal
        new->ant = cl->last; // o antigo ultimo elemento passa a ser o elemento anterior do novo nó
        cl->last->prox = new; // O penultimo elemento agora tera seu ponteiro prox apontando para o ultimo nó
        cl->last = new; // o ponteiro de ultimo agora aponta para o novo nó inserido
        
        //Atualizando ponteiros para lista circular.
        cl->last->prox = cl->first->prox;
        cl->first->prox->ant = cl->last;

    }

    cl->size++;
}

void CList_RemoveCNode(CList *cl, int val){

    if(!CList_isEmpty(cl)){

        CNode *p = cl->first->prox; //Primeiro elemento da lista.

        // O elemento procurado é o primeiro da lista.
        if(p->val == val){

            //A lista possui apenas um unico elemento?
            if(p == cl->last){

                cl->first->prox = NULL;
                cl->last = NULL;

            }else{

                cl->first->prox = p->prox;
                cl->first->prox->ant = cl->last;
                cl->last->prox = cl->first->prox;

            }

            free(p);
            cl->size--;
        
        }else if(p->val != val){ // verificaçao necessaria apenas para ter um else no final no caso de a lista estiver vazia.
            
            p = p->prox; //Se o elemento nao esta no inicio, ja começa a partir do segundo elemento a verificaçao.

            while(p != cl->first->prox){

                if(p->val == val){
                    
                    if(p == cl->last){ //O elemento encontrado esta na ultima posição da lista.

                        cl->last = p->ant;// O penultimo elemento agora será o ultimo
                    
                    }    
                    
                    //Atualiza ponteiros para continuar a lista circular
                    p->ant->prox = p->prox; // O ultimo elemento aponta para o primeiro elemento da lista.
                    p->prox->ant = p->ant; // O anterior do primeiro elemento aponta para o ultimo

                    free(p);
                    cl->size--;
                    break;

                }else{

                    p = p->prox;
                }
            }

        }
    }
    
}

void CList_DestroyList(CList *cl){

    CNode *p = cl->first;
    CNode *aux = NULL;

    while(p != cl->last){//Tambem poderia ser usado um

        aux = p;
        p = p->prox;
        free(aux);
    }

    free(p);
    cl = NULL;
    // Lista Circular Duplamente Encadeada desalocada!
}
