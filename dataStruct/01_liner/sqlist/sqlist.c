#include <stdio.h>
#include <stdlib.h> //malloc函数需要
#include <string.h> //memset函数需要
#include "sqlist.h"

/**
 * 创建
 */
sqlink list_create() {
    //1、malloc 申请内存
    sqlink L;
    L = (sqlink)malloc(sizeof(sqlist)); //malloc返回的是地址
    if(L == NULL){
        printf("list malloc failed\n");
        return L;
    }

    //2、initialize 初始化
    /* memset(填充内存起始地址，用什么填充，字节数) */
    memset(L, 0, sizeof(sqlist)); // 内存初始化为0
    L->last = -1; //空值，后面没数据了

    //3、return 返回线性表地址
    return L;
}; 

/**
 * 置空 0-success -1-failed (表在，数据没了)
 */
int list_clear(sqlink L){
    if(L == NULL){
        return -1;
    }
    memset(L, 0, sizeof(sqlist)); 
    L->last = -1;
    return 0;
}; 

/**
 * 销毁(内存释放)
 */
int list_free(sqlink L){
    if(L==NULL)
        return -1;
    free(L);
    L = NULL;
    return 0;
}

/**
 * list_empty():is list empty? 1-empty 0-notEmpty
 */
int list_empty(sqlink L){
    if(L->last == -1)
        return 1;
    else
        return 0;
}; 

// 表的长度
int list_length(sqlink L){
    if(L==NULL)
        return 0;
    return (L->last + 1);
}; 

/**
 * 定位函数:value是否在线性表L中 -1：不存在
 */
int list_locate(sqlink L,data_t value){
    int i;
    for ( i = 0; i <= L->last; i++){
        if (value==L->data[i]){
            return i;
        }
    }
    return -1;
}; 

/**
 * 插入数据
 */
int list_insert(sqlink L, data_t value, int pos){
    int i;
    //1、确定表是否满了
    if(L->last==N-1){
        printf("list is full\n");
        return -1;
    }

    //2、pos∈[0,last+1]
    if(pos<0||pos>L->last+1){
        printf("Pos is invalid\n");
        return -1;
    }

    //3、中间插入会有字节的移动（从后往前）
    for ( i = L->last; i >=pos; i--){
        L->data[i+1] = L->data[i]; // 往后移动
    }
    
    //4、存新值，更新last
    L->data[pos] = value;
    L->last++;

    return 0;
}; 

/**
 * 遍历线性表
 */
int list_show(sqlink L) {
    int i;
    if(L==NULL)
        return -1;
    if(L->last==-1){
        printf("list is empty\n");
    }

    for ( i = 0; i < L->last+1; i++){
        printf("%d\t", L->data[i]);
    }
    puts("");//输出一个空行
    return 0;
};

/**
 * 删除特定位置的数据
 */
int list_delete(sqlink L, int pos) {
    int i;
    if(L->last==-1){
        printf("list is empty\n");
        return -1;
    }
    //1、合理范围 pos∈[0,last]
    if(pos>L->last||pos<0){
        printf("delete pos is invalid\n");
        return -1;
    }

    //2、移动 覆盖范围[pos+1,last]
    for ( i = pos+1; i <= L->last ; i++){
        L->data[i-1] = L->data[i];
    }

    //3、更新
    L->last--;

    return 0;
};

/**
 * 线性表的合并 L1∪L2
 */
int list_merge(sqlink L1,sqlink L2){
    int i=0;
    int ret;
    while (i<=L2->last){
        ret=list_locate(L1, L2->data[i]);//L2的元素是否在L1中
        if (ret==-1){
            if(list_insert(L1,L2->data[i],L1->last + 1)==-1)
                return -1; // 插入最后效率最高
        }
        i++;
    }
    return 0;
};

/**
 * 删除元素中的重复数据
 */
int list_purge(sqlink L) {
    int i;
    int j;

    if (L->last==0)//就一个数不需要比较
        return 0;

    i = 1;

    while(i<=L->last){
        j = i - 1;
        while (j>=0){
            if(L->data[i]==L->data[j]){
                list_delete(L,i);
                break;
            }else{
                j--;
            }
        }
        if (j<0){
            i++;
        }
    }
    return 0;
};
