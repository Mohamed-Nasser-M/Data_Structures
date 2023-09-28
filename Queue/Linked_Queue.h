#define queue_entry int
struct QueueNode{
    queue_entry entry;
    struct QueueNode *next;
};
typedef struct queue{
    struct QueueNode *front;
    struct QueueNode *rear;
    int size;
}linked_Queue;
void creat_queue    (linked_Queue*);
void append   (queue_entry,linked_Queue*);
void serve    (linked_Queue*);
int queue_empty  (linked_Queue*);
int queue_full   (linked_Queue*);
int queue_size   (linked_Queue*);
void clear_queue (linked_Queue*);
void traverse_queue  (linked_Queue*,void(*)(queue_entry));
