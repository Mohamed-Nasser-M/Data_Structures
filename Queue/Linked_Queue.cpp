#include "Linked_Queue.h"
#include <iostream>
void creat_queue(linked_Queue *pq){
    pq->front= nullptr;
    pq->rear=nullptr;
    pq->size=0;
}
void append(queue_entry e, linked_Queue* pq){
    struct QueueNode* pn=(QueueNode*) malloc(sizeof(QueueNode));;
    pn->next = nullptr;
    pn->entry = e;
    if (!pq->rear)
        pq->front = pn;
    else
        pq->rear->next = pn;
    pq->rear = pn;
    pq->size++;
}
void serve(linked_Queue* pq){
    QueueNode *pn=pq->front;
    pq->front=pn->next;
    free(pn);
    if(!pq->front)
        pq->rear=nullptr;
    pq->size--;
}
int queue_empty(linked_Queue* pq){
    return !pq->front; // or !pq->rear; or !size;
}
int queue_full(linked_Queue* pq){
    return 0;
}
int queue_size(linked_Queue* pq){
    return pq->size;
}
void clear_queue(linked_Queue * pq){
    while(pq->front){
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void traverse_queue(linked_Queue* pq,void(*pf)(queue_entry)){
    for(QueueNode *pn=pq->front;pn;pn=pn->next)
        (*pf)(pn->entry);
}
