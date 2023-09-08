#define stack_entry int
typedef struct StackNode{
    stack_entry entry;
    struct StackNode *next;
} stack_node;
typedef struct stack{
    stack_node *top;
    int size;
} Stack;
void emplace    (stack_entry*,Stack*);
void push   (stack_entry,Stack*);
void pop    (Stack*);
int stack_empty  (Stack*);
int stack_full   (Stack*);
void creat_stack (Stack*);
stack_entry stack_top   (Stack*);
int stack_size   (Stack*);
void clear_stack (Stack*);
void traverse_stack  (Stack*,void(*)(stack_entry));