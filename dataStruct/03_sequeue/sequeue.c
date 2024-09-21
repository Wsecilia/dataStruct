#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequeue.h"

/**
 * 1、创建队列;
 */
sequeue *queue_create(){
    sequeue *sq;

    if ((sq=(sequeue*)malloc(sizeof(sequeue)))==NULL){
        printf("malloc failed!!\n");
        return NULL;
    }

    // sq->data 是队列存储元素的数组;
    memset(sq->data, 0, sizeof(sq->data)); // sizeof(sq->data) 确定数组的大小;
    sq->front = sq->rear = 0;              // 空队列;

    return sq;
}; 

/**
 * 2、入队;
 */
int enqueue(sequeue *sq, dataType x){
    if (sq==NULL){
        printf("sq is NULL!!\n");
        return -1;
    }

    if ((sq->rear+1)%N==sq->front){
        printf("sq is full!!\n");
        return -1;
    }

    sq->data[sq->rear] = x;
    sq->rear = (sq->rear + 1) % N; // 确保即使 rear 指针超过了数组的末尾，它也会循环回到数组的开始位置;
}; 

dataType dequeue(sequeue *sq);        // 出队;
int queue_empty(sequeue *sq);                    // 判断队列是否为空;
int queue_full(sequeue *sq);                     // 判断队列是否已满;
int queue_clear(sequeue *sq);                    // 队列清空;
sequeue *queue_free(sequeue *sq);                // 队列销毁;