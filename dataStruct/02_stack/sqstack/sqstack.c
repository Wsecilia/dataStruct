#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqstack.h"

/**
 * 1、栈的创建
 */
sqstack *stack_create(int len){
    sqstack *s;

    if ((s=(sqstack *)malloc(sizeof(sqstack)))==NULL){
        printf("malloc sqstack failed!!\n");
        return NULL;
    }

    if ((s->data=(data_t *)malloc(sizeof(len*sizeof(data_t))))==NULL){
        printf("malloc data failed!!\n");
        return NULL;
    }

    memset(s->data, 0, len * sizeof(data_t));
    s->maxlen = len;
    s->top = -1; // 空栈;
    return s;
}; 

/**
 * 2、入栈; 
 *    返回值int确认是否入栈成功;
 */
int stack_push(sqstack *s, data_t value){
    //检验参数
    if (s==NULL){
        printf("s is NULL");
        return -1;
    }
    
    //判断栈是否已满
    if (s->top==s->maxlen-1){
        printf("stack is full!!\n");
        return -1;
    }

    s->top++;
    s->data[s->top] = value; // 入栈;

    return 0;
}; 

/**
 * 3、判断栈是否为空;
 */
int stack_empty(sqstack *s){
    //检验参数
    if (s==NULL){
        printf("s is NULL");
        return -1;
    }

    //三目运算：成立为1，不成立为0
    return (s->top == -1 ? 1 : 0);
}; 

/**
 * 4、判断栈是否已满;
 */
int stack_full(sqstack *s){
    //检验参数
    if (s==NULL){
        printf("s is NULL");
        return -1;
    }

    //三目运算：成立为1，不成立为0
    return (s->top == s->maxlen - 1 ? 1 : 0);
};               

/**
 * 5、出栈; 
 *    返回是栈顶的数据值，格式是data_t
 */
data_t stack_pop(sqstack *s){
    s->top--;

    // top--;栈顶的值也要变成原栈顶前面的值
    return s->data[s->top + 1];
};             

/**
 * 6、查询栈顶的值;
 */
data_t stack_top(sqstack *s){
    return s->data[s->top];
};      

/**
 * 7、栈的清空;
 */
int stack_clear(sqstack *s){
    if (s==NULL){
        printf("s is NULL!!\n");
        return -1;
    }

    s->top = -1; // top=-1表示空栈，也就是清空栈;
    return 0;
};   

/**
 * 8、栈的销毁;
 */
int stack_free(sqstack *s){
    if (s==NULL){
        printf("s is NULL!!\n");
        return -1;
    }

    if (s->data!=NULL){
        free(s->data);
    }

    free(s);
    return 0;
};               
