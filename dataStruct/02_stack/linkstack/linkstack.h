typedef int data_t;

typedef struct node{
    data_t data;
    struct node *next;
}listnode,*linkstact;

linkstact stack_create(); // 链式栈的创建;
int stack_push(linkstact s, data_t value); // 入栈;
data_t stack_pop(linkstact s);             // 出栈;
int stack_empty(linkstact s);              // 判空;
data_t stack_top(linkstact s);             // 查询栈顶的值;
linkstact stack_free(linkstact s);         // 栈的销毁;
