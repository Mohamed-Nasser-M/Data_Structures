#include "Stack.h"
void creat_stack(Stack *ps){
    ps->top=0;
}
int stack_full(Stack *ps){
    return ps->top >=MAX_STACK;
}
void push(stack_entry e, Stack *ps){
    if(!stack_full(ps)){
        ps->entry[ps->top]=e;
        ps->top++;
    }
}
void emplace(stack_entry *e, Stack *ps){
    if(!stack_full(ps)){
        ps->entry[ps->top]=*e;
        ps->top++;
    }
}
void pop(Stack *ps){
    if(!stack_empty(ps)){
        ps->top--;
    }
}
int stack_empty(Stack *ps){
    return !ps->top;
}
stack_entry stack_top(Stack *ps){
    return ps->entry[ps->top-1];
}
int stack_size(Stack *ps){
    return ps->top;
}
void clear_stack(Stack *ps){
    ps->top=0;
}
void traverse_stack(Stack *ps, void(*pf)(stack_entry)){
    for(int i=ps->top; i>0; i++)
        (*pf)(ps->entry[i-1]);
}