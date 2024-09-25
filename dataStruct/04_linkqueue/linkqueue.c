#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"

/**
 * 1、创建
 */
linkqueue *queue_create(){
    linkqueue *lq;

    //①：为链式队列结构体分配内存
    if ((lq = (linkqueue*)malloc(sizeof(linkqueue)))==NULL){
        printf("malloc linkqueue failed!!\n");
        return NULL;
    }

    //②：为链式队列的头结点分配内存，并将头结点指针赋值给 front 和 rear 成员。
    lq->front = lq->rear = (linklist)malloc(sizeof(listnode));
    if (lq->front==NULL){
        printf("malloc node failed!!\n");
        return NULL;
    }

    //③：空队列
    lq->front->data = 0;
    lq->front->next = NULL;

    return lq;
};

/**
 * 2、入队 链尾入;
 */
int enqueue(linkqueue *lq, dataType value){
    // 指向 listnode 结构体的指针;
    linklist p;

    // 参数检查;
    if (lq==NULL){
        printf("lq is NULL!!\n");
        return -1;
    }

    // 创建新结点,为新结点分配内存;
    if ((p=(linklist)malloc(sizeof(listnode)))==NULL){
        printf("malloc node failed\n");
        return -1;
    }

    // 初始化新结点;
    p->data = value;
    p->next = NULL;

    lq->rear->next = p; // 将队列头结点front的next指针指向新结点p;
    lq->rear = p;        // 更新队列尾指针rear为新结点p;

    return 0;

};

/**
 * 3、出队 链头出;
 */
dataType dequeue(linkqueue *lq){
    linklist p;

    // 参数检查;
    if (lq==NULL){
        printf("lq is NULL!!\n");
        return -1;
    }

    // ①：找到指针指向要删除的;
    p = lq->front; // 删除头结点front，p就成为头结点了;

    // ②：更新指针的指向;
    lq->front = p->next;

    // ③：释放内存;
    free(p);
    p = NULL;

    return (lq->front->data);
};            

/**
 * 4、队列判空
 */
int queue_empty(linkqueue *lq){
    // 参数检查;
    if (lq==NULL){
        printf("lq is NULL!!\n");
        return -1;
    }

    return (lq->front == lq->rear ? 1 : 0);
};            


/**
 * 5、清空队列,保留头结点,clear比free多一个头结点
 */
int queue_clear(linkqueue *lq){
    linklist p;

    if (lq==NULL){
        printf("lq is NULL!!\n");
        return -1;
    }

    //释放内侧,原理同‘删除’
    while (lq->front->next){
        p = lq->front;
        lq->front = p->next;
        printf("clear:%d\n", p->data);
        free(p);
        p = NULL;
    }
};           

/**
 * 6、队列销毁
 */
linkqueue* queue_free(linkqueue *lq){
    linklist p;

    if (lq==NULL){
        printf("lq is NULL!!\n");
        return NULL;
    }

    //释放内侧,原理同‘删除’
    while (lq->front)// 当点存在时;
    { 
        p = lq->front;
        lq->front = p->next;
        printf("free:%d\n", p->data); // 头结点删掉，剩下的是出队的最后一个结点值;
        free(p);
    }

    //释放外侧
    free(lq);
    lq = NULL;

    return NULL;
};              

