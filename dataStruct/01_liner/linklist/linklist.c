#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/**
 * 1、创建
 */
linklist list_create(){
    linklist H;
    //①：申请内存
    H = (linklist)malloc(sizeof(listnode));
    if (H==NULL){
        printf("malloc failed!\n");
        return H;
    }
    //②：赋初值
    H->data = 0;
    H->next = NULL;
    //③：返回
    return H;
};

/**
 * 2、尾部插入，H代表头指针
 */
int list_tail_insert(linklist H,data_t value){
    linklist p; // 新结点的指针
    linklist q; // 临时指针
    //①：参数检查
    if (H==NULL){
        printf("H is NULL");
        return -1;
    }

    //②：建立一个新结点→malloc、赋值
    if ((p=malloc(sizeof(listnode)))==NULL){
        printf("malloc failed!!!\n");
        return -1;
    }
    p->data = value; // 新节点的值就是用户输入的数据
    p->next = NULL; // next尾结点，后面没有值了

    //③：定位尾结点(q->next==NULL)
    q = H;
    while (q->next!=NULL){
        q = q->next;
    }
    
    //④：尾部插入
    q->next = p;
    return 0;
}; 

/**
 * 3.1、链表查找-按位置查找结点
 *    与插入联合使用，找到插入位置的前一个结点位置即可
 */
linklist list_get(linklist H, int pos) {
    linklist p;
    int i;

    //①：H==NULL非法
    if (H==NULL){
        printf("H is NULL\n");
        return NULL;
    }

    //②：pos=-1 空链表
    if(pos==-1){
        return H;
    }

    if (pos<-1){
        printf("this pos is invild\n");
        return NULL;
    }   

    //③：循环
    p = H;
    i = -1; // 从-1开始
    while (i<pos){
        p = p->next;
        if (p==NULL){//位置太大了
            printf("this pos is invild\n");
            return NULL;
        }  
        i++;
    }

    return p;
};

/**
 * 4、链表插入
 */
int list_insert(linklist H, data_t value, int pos) {
    linklist p;
    linklist q;

    if (H==NULL){
        printf("H is NULL\n");
    }
    

    //①：找到插入位置的前一个位置
    p = list_get(H, pos - 1);
    if (p==NULL){
        return -1;
    }
    

    //②：生成新结点q
    if ((q=(linklist)malloc(sizeof(listnode)))==NULL){
        printf("malloc failed!!!\n");
        return - 1;
    }
    q->data = value;
    q->next = NULL;

    //③：插入
    q->next = p->next;
    p->next = q;

    return 0;
};

/**
 * 5、链表的删除
 */
int list_delete(linklist H, int pos) {
    linklist p;
    linklist q;
    //①：检查参数
    if (H==NULL){
        printf("H is NULL");
        return -1;
    }

    //②：找删除结点的前驱
    p = list_get(H, pos - 1);
    if (H==NULL)
        return -1;
    if (p->next==NULL){
        printf("delete pos is invalid!!!\n");
        return -1;
    }
    
    //③：更正-赋值、改指针
    q = p->next; // 赋值
    p->next = q->next; // 改指针
    
    //④：删除
    printf("the value of free is %d\n", q->data);
    free(q);

    return 0;
};

/**
 * 6、链表遍历
 */
int list_show(linklist H){
    linklist p;

    //参数检查
    if (H==NULL){
        printf("list is null\n");
        return -1;
    }

    p = H; // p指向H的头结点
    while (p->next!=NULL){
        printf("%d\t", p->next->data);
        p = p->next;
    }

    puts("");
    return 0;
};

/**
 * 7、链表释放
 */
linklist list_free(linklist H){
    linklist p;

    if(H==NULL)
        return NULL;

    p = H;

    printf("free linklist!!\n");
    while (H!=NULL){
        p = H;
        printf("%d-", p->data);
        free(p);
        H = H->next;
    }
    puts("");

    return 0;
};

/**
 * 8、链表翻转
 */
int list_reverse(linklist H){
    linklist p;
    linklist q;

    //链表为空
    if (H==NULL){
        printf("H is empty!!!\n");
        return -1;
    }
    //只有一个结点或两个结点,H不变(H->next是第一个结点)
    if (H->next==NULL || H->next->next==NULL){
        return 0;
    }

    // 链表一分为二，p指向待操作的点，q用来辅助完成插入
    p = H->next->next; //p 初始化为第一个要反转的结点（跳过头结点 H）。
    H->next->next = NULL;  //将头结点的下一个结点的 next 指针设置为 NULL，这是新的尾结点。

    /**
     *  这个循环用于逐个处理结点，直到 p 到达链表的末尾（p 为 NULL）。
        q 用于临时存储当前结点。
        将 q 的 next 指针指向当前头结点的下一个结点，实现反转。
        更新头结点的下一个结点为 q，即将 q 移动到头部。
     */
    while (p!=NULL){
        q = p;
        p = p->next;//p往后移动

        q->next = H->next;
        H->next = q;
    }
    
    return 0;
};

/**
 * 9、求相邻两个结点的最大值的第一个结点指针
 */
linklist list_adjmax(linklist H,data_t *value){
    linklist p, q, r;
    data_t sum;

    //1、校验参数
    if (H==NULL){
        printf("H is NULL\n");
        return NULL;
    }

    /**
     *  H->next == NULL：表示链表中没有数据结点，即第一个数据结点为空。
        H->next->next == NULL：表示链表中只有一个数据结点，即第二个数据结点为空。
        H->next->next->next == NULL：表示链表中只有两个数据结点，即第三个数据结点为空。
     */
    if (H->next==NULL&&H->next->next==NULL||H->next->next->next==NULL){
        return H;
    }

    q = H->next;       // 第一个结点;
    p = H->next->next; // 第二个结点，也可写成q->next;
    r = q;             // 初始值;
    sum = q->data + q->data;

    while (p->next!=NULL){
        p = p->next;
        q = q->next;
        if(sum<q->data+p->data){
            sum = q->data + p->data;
            r = q; // 储存第一结点;
        }
    }

    *value = sum;

    return r;
}; 

/**
 * 10、单链表A、B按data值递增有序，将两表合为一表A，依旧递增有序;
 */
int list_merge(linklist H1, linklist H2){
    return 0;
};