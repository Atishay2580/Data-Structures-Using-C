#include "linkedList.h"

struct Node *findMiddle(struct Node *list){
    if(list == NULL) return NULL;
    struct Node *fast, *slow;
    fast = slow = list;
    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int main(){
    struct Node *list = NULL;
    addLast(&list,10);
    addLast(&list,20);
    addLast(&list,30);
    addLast(&list,40);
    show(list);
    struct Node *ans = findMiddle(list);
    show(ans);
}