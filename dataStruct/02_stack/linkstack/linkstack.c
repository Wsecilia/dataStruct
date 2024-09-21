#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

/**
 * 1、链式栈的创建;
 */
linkstact stack_create(){
    linkstact s;

    s = (linkstact)malloc(sizeof(listnode));
    if (s==NULL){
        printf("malloc failed!!\n");
        return NULL;
    }

    // 空栈;
    s->data = 0; 
    s->next = NULL;

    return s;
}; 

/**
 * 2、入栈;
 */
int stack_push(linkstact s, data_t value){
    linkstact p;

    if (s==NULL){
        printf("s is NULL!!\n");
        return -1;
    }

    p = (linkstact)malloc(sizeof(listnode));
    if (p==NULL){
        printf("malloc is failed!!\n");
    }
    p->data = value;
    // p->next = NULL;这是一个独立的节点，放到s头结点后面，可以省略;
    p->next = s->next;
    s->next = p;

    return 0;
}; 

/**
 * 3、出栈
 */
data_t stack_pop(linkstact s){
    linkstact p;
    data_t t;

    p = s->next;
    s->next = p->next;

    t = p->data; // t来保存删除的值;
    free(p);
    p = NULL;

    return t;
};    

/**
 * 4、判断栈是否为空
 */
int stack_empty(linkstact s){
    //判断指针是否为空
    if (s==NULL){
        printf("s is NULL!!\n");
        return -1;
    }

    //栈是否为空
    return (s->next == NULL ? 1 : 0);
};              

/**
 * 5、查询栈顶的值;
 */
data_t stack_top(linkstact s){
    return s->next->data;
};            

/**
 * 6、栈的销毁
 */
linkstact stack_free(linkstact s){
    linkstact p; // 辅助删除;

    if (s==NULL){
        printf("s is NULL!!\n");
        return NULL;
    }

    while (s!=NULL){
        p = s;
        s = s->next;
        printf("free:%d\n", p->data);
        free(p);
    }

    return NULL;
};         
