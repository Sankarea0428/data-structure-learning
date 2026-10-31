#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    // 新节点指向原栈顶
    newNode->next = top;   
    printf("入栈: %d\n", value);
     //新节点成为新栈顶 
    return newNode;         
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("栈为空！\n");
        return NULL;
    }
    struct Node* temp = top;
    printf("出栈: %d\n", top->data);
    //栈顶后移
    top = top->next;   
    free(temp);        
    return top;
}

bool isEmpty(struct Node* top) {
    return top == NULL;
}

int main() {
    struct Node* stackTop = NULL;  

    stackTop = push(stackTop, 100);  
    stackTop = push(stackTop, 200); 
    stackTop = push(stackTop, 300);  

    printf("栈顶: %d\n", stackTop->data); 

    stackTop = pop(stackTop); 
    stackTop = pop(stackTop);  
    stackTop = pop(stackTop); 

    if (isEmpty(stackTop)) {
        printf("栈已空\n");     
    }
    return 0;
}