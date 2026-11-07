#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int value;
    struct Node* next;
};
struct Node* createnewNode(int value){
    struct Node* newNode = malloc(sizeof(struct Node));
        if (newNode == NULL){
        return NULL;
    }
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
};
struct Node* arr[10] = {NULL};


//这个声明是错误的 因为我们arr是一个指向节点指针的数组 所以类型肯定是节点指针的
// void build_arr(int value){
//     int **arr = malloc(10 * sizeof(int*));
//     *arr[9] = {};
// }



void insert(struct Node* arr[], int value) {
    int index = value % 10;
    struct Node* newNode = createnewNode(value);

    if (newNode == NULL) {
        return;
    }
    newNode->next = arr[index];
    arr[index] = newNode;
    //每次有新的节点进入同一个哈希桶，它都会插到原来链表的最前面 头插法
}
void display(struct Node* arr[]){
    for(int i = 0;i<10;i++){
    struct Node* current = arr[i];
    while(current!=NULL){
        printf("%d -> ",current->value);
        current = current->next;
    }
    }
}
struct Node* search(struct Node* arr[], int target){
    int index = target % 10;
    struct Node* current = arr[index];
    while(current->value!=target){
        current = current->next;
        if (current==NULL){
            return NULL;
        }
    }
    return current;
}


struct Node* delete(struct Node* arr[],int target){
    int index = target % 10;
    struct Node* previous = arr[index];
    struct Node* current = previous->next;
    while (current != NULL && current->value != target && previous->value!= target){
        previous = current;
        current = current->next;
        if (current==NULL){
            return NULL;
        }
    }
    if(previous->value== target){
        arr[index] = current;
        free(previous);
    }
    else{
    previous->next = current->next;
    free(current);
    }
}
//仍然存在三个问题 分别是 哈希桶空时会出错  只有一个节点 而且目标不存在的时候会出错  函数缺少成功删除的返回值


bool deleteValue(struct Node* arr[], int target) {

    int index = target % 10;

    struct Node* previous = NULL;
    struct Node* current = arr[index];

    while (current != NULL && current->value != target) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return false;
    }

    if (previous == NULL) {
        arr[index] = current->next;
    }
    else {
        previous->next = current->next;
    }

    free(current);

    return true;
}//这更加正确


int main(void) {

    // 1. 初始化哈希表
    struct Node* arr[10] = {NULL};

    // 2. 插入元素
    insert(arr, 42);
    insert(arr, 22);
    insert(arr, 12);
    insert(arr, 32);

    printf("===== Initial Hash Table =====\n");
    display(arr);

    // 3. 测试查找
    printf("\n===== Search Test =====\n");

    struct Node* result = search(arr, 22);

    if (result != NULL) {
        printf("Found: %d\n", result->value);
    }
    else {
        printf("Not found\n");
    }

    // 4. 测试不存在的元素
    printf("\n===== Delete Missing Element =====\n");

    if (deleteValue(arr, 52)) {
        printf("Deleted successfully\n");
    }
    else {
        printf("Element not found\n");
    }

    display(arr);

    // 5. 删除中间节点 22
    printf("\n===== Delete Middle Node =====\n");

    deleteValue(arr, 22);
    display(arr);

    // 6. 删除尾节点 42
    printf("\n===== Delete Tail Node =====\n");

    deleteValue(arr, 42);
    display(arr);

    // 7. 删除头节点 32
    printf("\n===== Delete Head Node =====\n");

    deleteValue(arr, 32);
    display(arr);

    // 8. 删除最后一个节点 12
    printf("\n===== Delete Last Node =====\n");

    deleteValue(arr, 12);
    display(arr);

    // 9. 检查哈希表是否为空
    printf("\n===== Final Hash Table =====\n");

    display(arr);

    // 10. 释放剩余内存（防止内存泄漏）
    for (int i = 0; i < 10; i++) {

        struct Node* current = arr[i];

        while (current != NULL) {

            struct Node* temp = current;
            current = current->next;

            free(temp);
        }
    }

    return 0;
}