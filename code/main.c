#include "clist.h"

int main(){
    
    CList l;

    CList_CreateCircularList(&l);

    CList_InsertInHead(&l,3);
    CList_InsertInHead(&l,2);
    CList_InsertInHead(&l,1);
    CList_InsertFinalList(&l,4);
    CList_InsertFinalList(&l,5);
    CList_InsertFinalList(&l,6);

    CList_PrintCList(&l);
    CList_PrintInvertCList(&l);

    //CList_DestroyList(&l);

    return 0;
}