#define stack_entry int
typedef struct StackNode{
    stack_entry entry;
    struct StackNode *next;
} stack_node;
typedef struct stack{
    stack_node *top;
    int size;
} linked_Stack;
void emplace    (stack_entry*,linked_Stack*);
void push   (stack_entry,linked_Stack*);
void pop    (linked_Stack*);
int stack_empty  (linked_Stack*);
int stack_full   (linked_Stack*);
void creat_stack (linked_Stack*);
stack_entry stack_top   (linked_Stack*);
int stack_size   (linked_Stack*);
void clear_stack (linked_Stack*);
void traverse_stack  (linked_Stack*,void(*)(stack_entry));
void reverse(linked_Stack*);
