#include "Linked_Stack.h"
#include <iostream>
void creat_stack(linked_Stack *ps){
    ps->top= nullptr;
    ps->size=0;
}
int stack_full(linked_Stack *ps){
    return 0;
}
void push(stack_entry e, linked_Stack *ps){
    stack_node *pn=(StackNode*) malloc(sizeof(StackNode));
    pn->entry=e;
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
}
void emplace(stack_entry *e, linked_Stack *ps){
    stack_node *pn=(StackNode*) malloc(sizeof(StackNode));
    pn->entry=*e;
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
}
void pop(linked_Stack *ps){
    if(ps->size){
        StackNode *pn;
        pn=ps->top;
        ps->top=ps->top->next;
        free(pn);
        ps->size--;
    }
}
int stack_empty(linked_Stack *ps){
    return ps->top==NULL;
}
stack_entry stack_top(linked_Stack *ps){
    return ps->top->entry;
}
int stack_size(linked_Stack *ps){
    return ps->size;
}
void clear_stack(linked_Stack *ps){
    StackNode *pn=ps->top;
    while(pn){
        pn=pn->next;
        free(ps->top);
        ps->top=pn;
    }
    ps->size=0;
}
void reverse(linked_Stack *ps){
    StackNode *pRun1=ps->top,*pRun2=ps->top,*pSafe=ps->top;
    while(pSafe->next){
        pSafe=pSafe->next;
    }
    int count1=ps->size-2;
    while(count1>=0){
        pRun1=ps->top;
        pRun2=ps->top;
        for(int i=0; i<count1; i++){
            pRun1=pRun1->next;
            pRun2=pRun2->next;
        }
        pRun2=pRun2->next;
        pRun2->next=pRun1;
        count1--;
    }
    pRun1->next= nullptr;
    ps->top=pSafe;
}
void traverse_stack(linked_Stack *ps, void(*pf)(stack_entry)){
    for(StackNode *pn=ps->top;pn;pn=pn->next)
        (*pf)(pn->entry);
}
