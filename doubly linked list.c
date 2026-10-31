#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
};
struct Node* buildnewNode(int value){
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
    return NULL;
}
        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = NULL;
    return newNode;
}
struct Node* insertInHead(struct Node* head,int value){
    struct Node* newHead = buildnewNode(value);
    if(head != NULL){
        newHead->next = head;
        head->prev = newHead;
    }
    return newHead;
}
void insertAfter(struct Node* preNode,struct Node* nextNode,int value){
    struct Node* newNode = buildnewNode(value);
    // if (newNode != NULL){
    //     newNode->prev = preNode;
    //     newNode->next = nextNode;
    //     preNode->next = newNode;
    //     nextNode->prev = newNode;
    // }
    // 如果 preNode == NULL，就不能访问 preNode->next。



    // 如果 nextNode == NULL，就不能访问 nextNode->prev。
        if (preNode == NULL || preNode->next != nextNode) {
        return;
    }

    struct Node* newNode = buildnewNode(value);

    if (newNode == NULL) {
        return;
    }

    newNode->prev = preNode;
    newNode->next = nextNode;

    preNode->next = newNode;

    if (nextNode != NULL) {
        nextNode->prev = newNode;
    }
}
struct Node* deleteNode(struct Node* head,struct Node* del) {
    // struct Node** ptr_del = del;
    if (del == NULL) {
        return head;
    }
    if(del->prev != NULL){
        del->prev->next = del->next;
    }
    else{
         head = del->next;
    }
    if(del->next != NULL){
        del->next->prev = del->prev;
    }
    
    
    if(del != NULL){
    del->next = NULL;
    del->prev = NULL;
    }
    // free(ptr_del)
    // 删除函数根本不需要这个二级指针。释放节点时，直接使用free(del);
    // 之前额外声明 target 关键在于是否已经有一个指针保存着待释放节点的地址，以及你是否会在释放前覆盖这个地址。
    free(del);
    return head;
}
void traverseForward(struct Node* head) {
    printf("正向遍历: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}
void traverseBackward(struct Node* head) {
    if (head == NULL) return;

    // 先走到最后一个节点
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // 从尾部沿 prev 方向返回头部 
    printf("反向遍历: ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->prev;
    }
}
