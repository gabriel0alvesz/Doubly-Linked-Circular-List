#include "clist.h"

int main(){
    
    CList l;

    CList_CreateCircularList(&l);

    CList_CreateCNode(4);

    CList_DestroyList(&l);

    return 0;
}