/* 展开写法，以后不用
struct sqlist_t
{
    data_t data[N];
    int last;
};

//为结构体和结构体指针重命名 
typedef struct sqlist_t sqlist; // sqlist L;struct sqlist L;
typedef struct sqlist_t *sqlink; // sqlink L;struct sqlink L;
*/
typedef int data_t;
#define N 128

typedef struct sqlist_t
{
    data_t data[N];
    int last;
}sqlist,*sqlink;

sqlink list_create(); // 创建
int list_clear(sqlink L); // 置空
int list_free(sqlink L); // 销毁
int list_empty(sqlink L); // 判断是否为空
int list_length(sqlink L); // 表的长度
int list_locate(sqlink L,data_t value); // 定位函数
int list_insert(sqlink L, data_t value, int pos); // 插入数据
int list_delete(sqlink L, int pos); // 删除特定位置的数据
int list_merge(sqlink L1, sqlink L2); // 求L1∪L2
int list_purge(sqlink L); // 删除线性表里面的重复元素
int list_show(sqlink L); // 遍历线性表