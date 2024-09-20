#include <stdio.h>
#include "sqstack.h"

int main(int argc, char const *argv[]){
    sqstack *s;

    s = stack_create(100);
    if (s==NULL){
        printf("failed!!\n");
        return -1;
    }
    //入栈
    stack_push(s, 10);
    stack_push(s, 30);
    stack_push(s, 50);
    stack_push(s, 70);

    //查询栈顶的值(最后入栈的值)
    data_t topValue = stack_top(s);
    printf("此时栈顶的值为：%d\n", topValue);

    //出栈
    while(!stack_empty(s)){
        printf("pop:%d\n", stack_pop(s));
    }

    stack_free(s);

    return 0;
}
