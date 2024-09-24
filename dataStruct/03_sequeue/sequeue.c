#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequeue.h"

/**
 * 1、创建队列;
*/
sequeue * queue_create() {
	sequeue *sq;

	if ((sq = (sequeue *)malloc(sizeof(sequeue))) == NULL) {
		printf("malloc failed\n");
		return NULL;
	}

    // sq->data 是队列存储元素的数组;
	memset(sq->data, 0, sizeof(sq->data));// sizeof(sq->data) 确定数组的大小;
	sq->front = sq->rear = 0;// 空队列;
	return sq;
}

/**
 * 2、入队;
 */
int enqueue(sequeue *sq, dataType x) {
	if (sq == NULL) {
		printf("sq is NULL\n");
		return -1;
	}

	if ((sq->rear + 1) % N == sq->front) {
		printf("sequeue is full\n");
		return -1;
	}

	sq->data[sq->rear] = x;
	sq->rear = (sq->rear + 1) % N;// 确保即使 rear 指针超过了数组的末尾,它也会循环回到数组的开始位置;

	return  0;
}

/**
 * 3、出队
 */
dataType dequeue(sequeue *sq) {
	dataType ret;

	ret = sq->data[sq->front];

    /**
     * 它将 sq->front 加 1（意味着向前移动一个位置），然后取模 N（数组的长度）。
     * 这样做是为了确保索引值在循环队列中循环，当到达数组末尾时又回到数组开头。
     * N 应该是定义在 sequeue 结构体或相关头文件中的常量，表示队列的最大容量。
     */
	sq->front = (sq->front + 1) % N;

	return ret;
}

/**
 * 4、判断队列是否为空;
 */
int queue_empty(sequeue *sq) {
	if (sq == NULL) {
		printf("sq is NULL\n");
		return -1;
	}

	return (sq->front == sq->rear ? 1 : 0);
}

/**
 * 5、判断队列是否已满;
 */
int queue_full(sequeue *sq) {
	if (sq == NULL) {
		printf("sq is NULL\n");
		return -1;
	}

	if ((sq->rear + 1) % N == sq->front) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * 6、队列清空
 */
int queue_clear(sequeue *sq) {
	if (sq == NULL) {
		printf("sq is NULL\n");
		return -1;
	}

	sq->front = sq->rear = 0;//空队列

	return 0;
}

/**
 * 7、队列销毁
 */
sequeue * queue_free(sequeue *sq) {
	if (sq == NULL) {
		printf("sq is NULL\n");
		return NULL;
	}

	free(sq);
	sq = NULL;

	return NULL;
}
