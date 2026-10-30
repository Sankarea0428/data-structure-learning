#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           
    struct Node* next;
};

void josephus(int n, int m) {
    if (n <= 0) return;

    // 创建包含 n 个人的循环链表
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = head;  //自环

    struct Node* tail = head;
    for (int i = 2; i <= n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        //新节点的 next 始终指向头
        newNode->next = head;   
        //前一个节点的 next 指向新节点
        tail->next = newNode; 
        //tail 后移 
        tail = newNode;          
    }
    struct Node* cur = head;
    struct Node* prev = tail; 
    //后面需要让删除节点的前驱连接到后面的节点 所以需要prev

    printf("约瑟夫环 (n=%d, m=%d) 淘汰顺序: ", n, m);

    while (cur->next != cur) {  
        //报数：数 m-1 次，让 prev 和 cur 同时前进
        for (int count = 1; count < m; count++) {
            prev = cur;
            cur = cur->next;
        }
        // 数到 m，cur 被淘汰
        printf("%d ", cur->data);
        prev->next = cur->next; 
        free(cur);              
        // 从下一个人重新开始报数
        cur = prev->next;        
    }

    printf("=> 最后幸存者: %d\n", cur->data);
    free(cur);
}

int main() {
    josephus(7, 3);
    return 0;
}