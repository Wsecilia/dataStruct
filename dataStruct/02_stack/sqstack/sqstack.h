typedef int data_t;

typedef struct {
    data_t *data;
    int maxlen;
    int top; // 栈顶;
}sqstack;

sqstack *stack_create(int len); // 栈的创建;
int stack_push(sqstack *s, data_t value); // 入栈; 返回值int确认是否入栈成功;
int stack_empty(sqstack *s);              // 判断栈是否为空;
int stack_full(sqstack *s);               // 判断栈是否已满;
data_t stack_pop(sqstack *s);             // 出栈; 返回是栈顶的数据值，格式是data_t
data_t stack_top(sqstack *s);             // 查询栈顶的值;
int stack_clear(sqstack *s);              // 栈的清空;
int stack_free(sqstack *s);               // 栈的销毁;
