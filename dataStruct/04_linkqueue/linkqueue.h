typedef int dataType;
/**
 * 定义链式队列的【结点】结构体
 * 它包含一个 dataType 类型的数据成员 data 和一个指向下一个结点的指针 next;
 * 定义了 listnode 为该结构体的别名，linklist 为指向该结构体的指针的别名。
 */
typedef struct node{
    dataType data; // 数据域;
    struct node *next; // 指针域;
} listnode, *linklist;

/**
 * 定义链式【队列】结构体
 * 包含两个 linklist 类型的成员，分别指向链式队列的前端和后端。
 */
typedef struct {
    linklist front; // 前端指针;
    linklist rear;  // 后端指针;
}linkqueue;

linkqueue *queue_create(); // 创建;
int enqueue(linkqueue *lq, dataType value); // 入队;
dataType dequeue(linkqueue *lq);            // 出队;
int queue_empty(linkqueue *lq);             // 判空;
int queue_clear(linkqueue *lq);             // 清空;
linkqueue* queue_free(linkqueue *lq);              // 销毁;
