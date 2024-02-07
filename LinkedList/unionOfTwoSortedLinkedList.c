#include "linkedList.h"

struct Node *Union(struct Node *list1, struct Node *list2){
    struct Node *list3 = NULL;
    while(list1 != NULL && list2 != NULL){
        if(list1 -> info < list2 -> info){
            addLast(&list3, list1 -> info);
            list1 = list1 -> next;
        }
        else if(list1 -> info == list2 -> info){
            addLast(&list3, list1 -> info);
            list1 = list1 -> next;
            list2 = list2 -> next;
        }
        else{
            addLast(&list3, list2 -> info);
            list2 = list2 -> next;
        }
    }
    while(list1 != NULL){
        addLast(&list3, list1 -> info);
        list1 = list1 -> next;
    }
    while(list2 != NULL){
        addLast(&list3, list2 -> info);
        list2 = list2 -> next;
    }
    return list3;
}

struct Node *Intersection(struct Node *list1, struct Node *list2){
    struct Node *list3 = NULL;
    while(list1 != NULL && list2 != NULL){
        if(list1 -> info == list2 -> info){
            addLast(&list3, list1 -> info);
            list1 = list1 -> next;
            list2 = list2 -> next;
        }
        else{
            list1 = list1 -> next;
            list2 = list2 -> next;
        }
    }
    return list3;
}

struct Node *Difference(struct Node *list1, struct Node *list2){
    struct Node *list3 = NULL;
    while(list1 != NULL && list2 != NULL){
        if(list1 -> info < list2 -> info){
            addLast(&list3, list1 -> info);
            list1 = list1 -> next;
        }
        else if(list1 -> info == list2 -> info){
            list1 = list1 -> next;
            list2 = list2 -> next;
        }
        else{
            list2 = list2 -> next;
        }
    }
    return list3;
}

struct Node *SymmetricDifference(struct Node *list1, struct Node *list2){
    struct Node *list3 = NULL;
    list3 = Union(Difference(list1,list2),Difference(list2,list1));
    return list3;
}

int main(){
    struct Node *list1, *list2, *list3;
    list1 = list2 = list3 = NULL;
    addLast(&list1,2);
    addLast(&list1,4);
    addLast(&list1,6);
    addLast(&list1,20);
    addLast(&list1,25);
    addLast(&list1,30);

    addLast(&list2,3);
    addLast(&list2,9);
    addLast(&list2,10);
    addLast(&list2,20);
    addLast(&list2,24);
    addLast(&list2,25);
    addLast(&list2,90);
    addLast(&list2,100);

    list3 = Union(list1,list2);
    show(list3);
    list3 = Intersection(list1,list2);
    show(list3);
    list3 = Difference(list1,list2);
    show(list3);
    list3 = Difference(list2,list1);
    show(list3);
    list3 = SymmetricDifference(list1,list2);
    show(list3);
}