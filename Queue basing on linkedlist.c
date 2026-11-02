#include<stdio.h>
#include<stdlib.h>
struct Queue {
    struct Queue* head;
    struct Queue* tail;
}
struct Node {
    int data;
    struct Node* next;
};

struct Queue* initialize(struct Queue* q){
    q->data = 0;
    q->head = q;
    q->tail = q;
}
struct Queue* add(struct Queue* q,int value){
    struct Queue* newQueue;
    newQueue->data = value;
    q->tail = newQueue;
}
struct Queue* out(struct Queue* q){
    struct Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
}
//链表版本过于简单不再书写