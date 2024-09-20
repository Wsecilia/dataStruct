typedef int data_t;

typedef struct node{
    data_t data;
    struct node *next;// 结点指针
}listnode,*linklist;

linklist list_create(); // 创建
int list_tail_insert(linklist H,data_t value); // 尾部插入，H代表头指针
linklist list_get(linklist H,int pos); // 按位置查找
int list_insert(linklist H, data_t value, int pos); // 插入结点
int list_delete(linklist H, int pos); // 链表删除
int list_show(linklist H); // 链表遍历
linklist list_free(linklist H); // 链表释放
int list_reverse(linklist H); // 链表翻转
linklist list_adjmax(linklist H,data_t *value); // 求相邻两个结点的最大值的第一个结点指针
int list_merge(linklist H1, linklist H2); // 单链表A、B按data值递增有序，将两表合为一表A，依旧递增有序;【链式排序】