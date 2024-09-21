#include <stdio.h>
#include "linkstack.h"

int main(int argc, char const *argv[]){
    linkstact s;
    int i;

    s = stack_create();
    if (s==NULL){
        printf("creat failed!!\n");
        return -1;
    }

    //入栈
    stack_push(s, 10);
    stack_push(s, 20);
    stack_push(s, 30);
    stack_push(s, 40);
    stack_push(s, 50);

    //查询栈顶top的值
    printf("栈顶的值为：%d\n",stack_top(s));

    //出栈
    while (!stack_empty(s)){
        printf("pop:%d\n", stack_pop(s));
    }

    //栈的销毁
    s = stack_free(s);

    return 0;
}
