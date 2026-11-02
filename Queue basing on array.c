#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Maxmize 100
struct Queue {
    int items[Maxmize];
    int head;
    int tail;
};
void initialize(struct Queue* q){
    q->items[Maxmize];
    q->head = 0;
    q->tail = 0;
}
bool isEmpty(struct Queue* q){
    return q->head == q->tail;
}
bool isFull(struct Queue* q){
    return q->tail == Maxmize;
}
void add(struct Queue* q, int value){
    if(!isFull(q)){
    q->items[q->tail] = value;
    q->tail++;
    }
}
int out(struct Queue* q){
    return q->items[q->head++];
}
    int main(void) {

    // 1. 创建队列
    struct Queue q;

    // 2. 初始化队列
    initialize(&q);

    // 3. 入队
    add(&q, 10);
    add(&q, 20);
    add(&q, 30);

    // 4. 查看队列状态
    printf("是否为空：%d\n", isEmpty(&q));
    printf("是否已满：%d\n", isFull(&q));

    // 5. 出队
    printf("出队：%d\n", out(&q));
    printf("出队：%d\n", out(&q));
    printf("出队：%d\n", out(&q));

    // 6. 检查是否为空
    if (isEmpty(&q)) {
        printf("队列已空\n");
    }

    return 0;
}