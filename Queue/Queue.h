#define queue_entry int
#define MAX_QUEUE 1000
typedef struct queue{
    int front,rear,size;
    queue_entry entry[MAX_QUEUE];
} Queue;
void creat_queue    (Queue*);
void append   (queue_entry,Queue*);
void serve    (Queue*);
int queue_empty  (Queue*);
int queue_full   (Queue*);
int queue_size   (Queue*);
void clear_queue (Queue*);
void traverse_queue  (Queue*,void(*)(queue_entry));
