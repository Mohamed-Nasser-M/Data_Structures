#include "Queue.h"
void creat_queue(Queue *pq){
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void emplace(queue_entry* e,Queue* pq){
    pq->rear=(pq->rear+1)%MAX_QUEUE;
    pq->entry[pq->rear]=*e;
    pq->size++;
}
void append(queue_entry e,Queue* pq){
    pq->rear=(pq->rear+1)%MAX_QUEUE;
    pq->entry[pq->rear]=e;
    pq->size++;
}
void serve(Queue* pq){
    pq->front=(pq->front+1)%MAX_QUEUE;
    pq->size--;
}
int queue_empty(Queue* pq){
    return pq->size;
}
int queue_full(Queue* pq){
    return (pq->size==MAX_QUEUE);
}
int queue_size(Queue* pq){
    return pq->size;
}
void clear_queue(Queue* pq){
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void traverse_queue(Queue* pq,void(*pf)(queue_entry)){
    int pos,s;
    for(pos=pq->front,s=0;s<pq->size;s++){
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAX_QUEUE;
    }
}
