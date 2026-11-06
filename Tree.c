#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
struct TreeNode{
    int value;
    struct TreeNode* Left;
    struct TreeNode* Right;
};
void initiallize(struct TreeNode* t){
    t->value = 0;
    t->Left = NULL;
    t->Right = NULL;
}
struct TreeNode* build(struct TreeNode* t,int value){
    struct TreeNode* newTreenode = malloc(sizeof(struct TreeNode));
    if(t->Left==NULL){
        t->Left = newTreenode;
    }
    else{
        t->Right = newTreenode;
    }
    newTreenode->value = value;
    newTreenode->Left = NULL;
    newTreenode->Right = NULL;
}
//这种写法 仍然存在不足：如果左右子节点都已经存在 怎么办？ 所以可以更正如下：
struct TreeNode* build_update(
    struct TreeNode* parent,
    int value,
    bool isLeft
) {
    if (parent == NULL) return NULL;

    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));

    if (newNode == NULL) return NULL;

    newNode->value = value;
    newNode->Left = NULL;
    newNode->Right = NULL;

    if (isLeft) {
        if (parent->Left != NULL) {
            free(newNode);
            return NULL;
        }
        parent->Left = newNode;
    }
    else {
        if (parent->Right != NULL) {
            free(newNode);
            return NULL;
        }
        parent->Right = newNode;
    }

    return newNode;
}
//明确指定方向 避免了自动链接 





//||||||||||||||||||||||||||||||||||||||||||||||
// void traverse(struct TreeNode* t){
//     struct TreeNode* current = t;
//     while(t->Left!=NULL){
//         current = t->Right;
//         print("%d",current->value);
//         current = t->Left;
//         print("%d",current->value);
//         t = current;
//     }
//这里不像线性表只有单独一种传递方式 同时无法访问之前的节点 所以while然后线性表传递做不到完全囊括
//|||||||||||||||||||||||||||||||||||||||||||||||

//前序递归
void postorder(struct TreeNode* t) {

    if (t == NULL) return;

    postorder(t->Left);

    postorder(t->Right);

    printf("%d ", t->value);
}

//中序递归
void inorder(struct TreeNode* t) {

    if (t == NULL) return;

    inorder(t->Left);

    printf("%d ", t->value);

    inorder(t->Right);
}//这里并不需要赋值指针 让指针指向下一个节点 而是直接选择用本体传递 


//////////////////////////
//链表可以做到吗？试验一下 
struct Node{
    int value;
    struct Node* next;
};
void order(struct Node* head){
    printf("%d",head->value);
    order(head->next);//发生了什么？似乎做到了 在order内做到了传递 避免了麻烦的current指针 这么看来似乎是更好的方法？
    //复记：本质上也是前序式的递归，只不过链表只有一个 next 分支，而二叉树有 Left 和 Right 两个分支
}
//////////////////////////


//后序递归
void preorder(struct TreeNode* t) {
    if (t == NULL) return;

    printf("%d ", t->value);

    preorder(t->Left);
    preorder(t->Right);
}
//三者不同 仅在于遇到节点后先打印本身 还是继续遍历到下一个再打印本身



//BST插入
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->value  = data;
        node->Left = node->Right = NULL;
        return node;
    }
    //创建节点的前提是发现了空位置
    if(data<root->value){
        root->Left = insert(root->Left, data); 
    }
    else if (data > root->value){
        root->Right = insert(root->Right,data);

    }
    //递归用来检索 不断向下推
     return root;
    }
struct TreeNode* search(struct TreeNode* root, int target){
    if(root == NULL||root->value == target){
        return root;
    }
        if (target < root->value) {
        return search(root->Left, target);   /* 目标更小，去左子树找 */
    }
    return search(root->Right, target);       /* 目标更大，去右子树找 */
}
void inorder_1(struct TreeNode* t){
    if (t == NULL) return;
    inorder_1(t->Left);
    printf("%d",t->value);
    inorder_1(t->Right);
}

int height(struct TreeNode* t) {

    // 递归终止条件：空树高度为 0
    if (t == NULL) {
        return 0;
    }

    // 分别计算左右子树的高度
    int leftHeight = height(t->Left);
    int rightHeight = height(t->Right);

    // 返回较高的子树高度 + 当前节点这一层
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main(){
    struct TreeNode* t = NULL;
    int value[] = {1,2,3,4,5,6,7,8,9};
    for(int i = 0;i<9;i++){
        t = insert(t,value[i]);
    }
    search(t,7);
    inorder_1(t);
}