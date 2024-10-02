#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int data_t;
#define N 128

typedef struct sqlist{
    data_t data[N];
    int last;
}sqlist,*sqlink;

/*
    1、创建
*/
sqlink list_create(){
    sqlink L;

    L = (sqlink)malloc(sizeof(sqlist));
    if (L==NULL){
        printf("L malloc failed!!!\n");
        return L;
    }

    memset(L, 0, sizeof(sqlist));
    L->last = -1;

    return L;
}

/*
    2、置空
*/
int list_clear(sqlink L){
    if (L==NULL){
        printf("L IS NULL!!\n");
        return -1;
    }

    memset(L, 0, list_length(L));

    return 0;
}

/**
 * 3、销毁
 */

/**
 * 4、判断是否为空
 */
int list_empty(sqlink L){
    return (L->last==-1?1:0);
}

/**
 * 5、表的长度
 */
int list_length(sqlink L){
    if (L==NULL){
        return -1;
    }
    
    return L->last + 1;
}

/**
 * 6、定位函数
 */

/**
 * 7、插入数据-尾插法
 */
int list_insert(sqlink L,data_t value,int pos){
    int i;

    if (L->last=N-1){
        printf("L is full\n");
        return -1;
    }

    if (pos<0||pos>L->last){
        printf("this pos is invalid\n");
        return -1;
    }

    for ( i = L->last; i >=pos; i--){
        L->data[i + 1] = L->data[i];
    }

    L->data[pos] = value;
    L->last++;

    return 0;
}

/**
 * 8、删除特定位置的数据
 */

/**
 * 9、求L1∪L2
 */

/**
 * 10、删除线性表的重复元素
 */

/**
 * 11、遍历线性表
 */
int list_show(sqlink L){
    int i;
    
    if (L==NULL)
        return -1;
    
    if(L->last==-1)
        printf("this list is empty!!");
    
    for ( i = 0; i < L->last+1; i++){
        printf("%d\t", L->data[i]);
    }
    puts("");
    return 0;
}


int main(int argc, char const *argv[]){
    sqlink L;
    L = list_create();
    printf("L表是否为空：%d", list_empty(L));
    list_insert(L, 10, 0);
    list_insert(L, 20, 0);
    list_insert(L, 30, 0);
    list_insert(L, 40, 0);
    return 0;
}
