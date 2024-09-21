typedef int dataType;
#define N 128 // 队列的长度;

typedef struct {
    dataType data[N];
    int front; // 头;
    int rear;  // 尾;
}sequeue;

sequeue *queue_create(); // 创建队列;
int enqueue(sequeue *sq, dataType x); // 入队;
dataType dequeue(sequeue *sq);        // 出队;
int queue_empty(sequeue *sq);                    // 判断队列是否为空;
int queue_full(sequeue *sq);                     // 判断队列是否已满;
int queue_clear(sequeue *sq);                    // 队列清空;
sequeue *queue_free(sequeue *sq);                // 队列销毁;