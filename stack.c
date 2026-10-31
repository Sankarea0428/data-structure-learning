#include <stdio.h>
#include <stdbool.h> 
#define Maxmize 100;
struct stack{
    int item[Maxmize];
    int top;
};
void initialize(struct stack* s){
    s->top = -1;
}
bool isEmpty(struct stack* s){
    return s->top == -1;
}
bool isFull(struct stack* s){
    return s->top == Maxmize -1;//这里为什么选择等于maxmize-1？
}
void push(struct stack *s,int value){
    if isFull(s){
        printf("当前栈已满");
        return;
    }
    else{
        s->item[++s->top] = value;
        
    }
}
int pop(struct stack* s,int value){
    if isEmpty(s){
        printf("当前栈已空");
        return;
    }
    return s->item[s->top--]
    };

int peek(struct stack* s) {
    if (isEmpty(s)) {
        printf("栈为空！\n");
        return -1;
    }
    return s->item[s->top];
}
int main() {
    struct stack s;
    initStack(&s);

    push(&s, 10);  
    push(&s, 20);  
    push(&s, 30);  

    printf("栈顶元素: %d\n", peek(&s));  

    printf("出栈: %d\n", pop(&s));        
    printf("出栈: %d\n", pop(&s));        
    printf("出栈: %d\n", pop(&s));        

    if (isEmpty(&s)) {
        printf("栈已空\n");                
    }
    return 0;
}
