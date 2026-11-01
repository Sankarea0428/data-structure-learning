#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define Maxmize 100
struct stack{
    char item[Maxmize];
    int top;
    };
void initialize(struct stack* s){
    s->top = -1;
};
bool isEmpty(struct stack* s){
    return s->top == -1;
}
bool isFull(struct stack* s){
    return s->top == Maxmize -1;
}
char peek(struct stack* s) {
    if (isEmpty(s)) return '\0';

    return s->item[s->top];
}

void push(struct stack* s,char value){
    if (isFull(s)) return;
    s->item[++s->top] = value;
}
char pop(struct stack* s){
        if (isEmpty(s)){
        printf("当前栈已空");
        return '\0';
    }
    return s->item[s->top--];
}
char finalanswer[100] = "";
//注意比较栈顶运算符和当前运算符的优先级。 所以我们采取return 1，2，3后面方便直接比较
int symbolPrior(char n){//判别符号优先级
    
    if(n=='+'||n=='-'){
        return 1;
    }
    if(n=='*'||n=='/'){
        return 2;
    }
    return 0;

} 
int outputIndex = 0;
bool scanner(char* str, struct stack* s){
        initialize(s);
    outputIndex = 0;
    finalanswer[0] = '\0';
    for(int n = 0; /*n<=strlen(str)*/str[n] != '\0';n++){//太麻烦
        // if (typeof(str[n]) == int){
        //     finalanswer[n] = &str[n];
        // }
        /*这里概念上有问题。

        str[n] 本身就是一个 char，我们需要判断的是：

        这个字符在表达式中属于操作数，还是运算符？*/
//因此 推荐使用#include <ctype.h>




//         if (isalnum((unsigned char)str[n])) {
//             finalanswer[outputIndex] = str[n];
//             outputIndex++;
//         }
//         else{
//             if(str[n]!='('&&str[n]!=')'){
//                 if(symbolprior(peek(s))==symbolPrior(str[n])){
//                     char temp = pop(s);
//                     finalanswer[outputIndex] = temp;
//                     outputIndex++;
//                 }
                
//                 if(isEmpty(s)||symbolprior(peek(s))<symbolPrior(str[n])){
//                     push(s,str[n]);
//                 }
//                 if(symbolprior(peek(s))>symbolPrior(str[n])){
//                     char temp = pop(s);
//                     push(s,str[n]);
//                     finalanswer[outputIndex] = temp;
//                     outputIndex++;
                    
//                 }
//         }
//         else{
//             if(str[n]=='('){
//                 push (s,str[n])
//             }
//             if(str[n]==')'){
//                 pop(s);
//             }
//         }
//         }
//纯纯狗屎代码 不知道在干什么 每次压入弹出都要参与一次判断 每次栈顶改变都要进行一次判断 所以判断条件应该是栈顶运算符的优先级大于或等于当前运算符，就应该弹出
//所以 用while表示判断 同时几个都满足 if表示单个 不要堆了
//     while (!isEmpty(s) &&peek(s) != '(' &&symbolPrior(peek(s)) >= symbolPrior(str[n])) {

//         finalanswer[outputIndex++] = pop(s);
//     }
//     if(str[n]==')'){
//         pop(s);
//         }
//     if (!isEmpty(s)) {
//         pop(s); 
// }
    if (isspace((unsigned char)str[n])) {
    continue;
}
    if (isalnum((unsigned char)str[n])) {

       finalanswer[outputIndex] = str[n];
       outputIndex++;

    }
    else if (str[n] == '(') {

        push(s,str[n]);

    }
else if (str[n] == ')') {

    while (!isEmpty(s) && peek(s) != '(') {
        finalanswer[outputIndex++] = pop(s);
    }

    if (isEmpty(s)) {
        printf("括号不匹配\n");
        return false;
    }

    pop(s);  // 丢弃匹配的左括号
}
    else {
        while (!isEmpty(s) &&peek(s) != '(' &&symbolPrior(peek(s)) >= symbolPrior(str[n])) {

         finalanswer[outputIndex++] = pop(s);
    }
        push(s,str[n]);
    }
}
while (!isEmpty(s)) {
    if (peek(s) == '(') {
        return false;
    }
    finalanswer[outputIndex++] = pop(s);
}
    finalanswer[outputIndex] = '\0';
    return true;
}
int main(void) {

    struct stack s;
    char expression[Maxmize];

    // 1. 获取用户输入
    printf("请输入中缀表达式：");

    if (fgets(expression, Maxmize, stdin) == NULL) {
        printf("输入失败\n");
        return 1;
    }

    // 2. 去掉 fgets 读取的换行符
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '\n') {
            expression[i] = '\0';
            break;
        }
    }

    // 3. 调用转换函数
    if (scanner(expression, &s)) {

        // 4. 转换成功，输出后缀表达式
        printf("后缀表达式：%s\n", finalanswer);

    }
    else {

        // 5. 转换失败
        printf("表达式不合法，转换失败\n");

    }

    return 0;
}
