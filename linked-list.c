#include <stdio.h>
#include <stdlib.h>
struct Node{
    int value;
    struct Node* next;
}
struct Node* createnewNode(int value){
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->next = NULL;
    newNode->value = value;
    if (newNode == NULL){
        return NULL;
    }
    return newNode;
}
void traverse(struct Node* head){
    struct Node* current = head;
    while (current != NULL){
        printf("%d",current->value);
        current = current->next;
    }
    }
struct Node* createlist(int n){
    struct Node* newNode= malloc(sizeof(struct Node));
    struct Node* head = newNode;
    struct Node* tail = head;
    head->value = 0;
    head->next = NULL;
    for(int count = 1; count<n;count++){
        struct Node* newNode= malloc(sizeof(struct Node));
        newNode->value = count;
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    return head;

    }
struct Node* deleteByValue(struct Node* head, int value) {
    if (head == NULL) return NULL;
    struct Node* current = head;
    // if(current->value==value){
    //     head->next = current->next;
    //     current->next = NULL;

    // }
    // else{
    //     head = head ->next
    // }
    if(head->value == value){
        struct Node* target = head;
        head = head->next;
        free(target);
        return head;
while (current->next != NULL){
    }
    if(current->next->value==value){
        struct Node* target = current->next;
        current->next = current->next->next;
        free(target);
        return head;
    }
    else{
        current  = current->next;
    }
    
}
}
