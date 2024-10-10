/**
 * 线性表-顺序表
 */
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
    2、在某个位置插入-尾插法
 */
int list_insert(sqlink L,data_t value,int pos){
    int i;

    if (L->last==N-1){
        printf("L is full\n");
        return -1;
    }

    if (pos<0||pos>L->last+1){
        printf("the pos is invalid\n");
        return -1;
    }

    for ( i = L->last; i >=pos; i--){
        L->data[i + 1] = L->data[i];
    }

    L->data[pos] = value;
    L->last++;

    return 0;
}

/*
    3、遍历顺序表
 */
int list_show(sqlink L){
    int i;

    if (L==NULL)
        return -1;

    if (L->last==-1)
        printf("the list is NULL\n");

    for (i = 0; i < L->last+1; i++){
        printf("%d\t", L->data[i]);
    }

    puts("");
    return 0;
}

/*
    4、删除某个位置的数据
 */
int list_delete(sqlink L,int pos){
    int i;

    if (L==NULL){
        printf("L is NULL\n");
        return -1;
    }

    if (pos<0||pos>L->last+1){
        printf("this pos is invalid\n");
        return -1;
    }

    for (i = pos + 1; i < L->last+1;i++){
        L->data[i-1] = L->data[i];
    }

    L->last--;

    return 0;
}

/*
    5、查询表的长度
 */
int list_length(sqlink L){
    if (L==NULL)
        return 0;
    return L->last + 1;
}

/*
    6、查找某值是否存在于线性表
*/
int list_locate(sqlink L,data_t value){
    int i;
    for ( i = 0; i < L->last+1; i++){
        if (L->data[i]==value){
            return i;
        }
    }

    return -1;
}

/*
    7、判断线性表是否为空
*/
int list_empty(sqlink L){
    if (L->last==-1){
        return 1;
    }else{
        return 0;
    }
}

/*
    8、置空
*/
int list_clear(sqlink L){
    if (L==NULL){
        printf("L is NULL\n");
        return -1;
    }
    
    memset(L, 0, sizeof(sqlist));

    return 0;
}

/*
    9、线性表的合并
*/
int list_merge(sqlink L1,sqlink L2){
    int i=0;
    int ret;
    while (i<=L2->last){
        ret = list_locate(L1, L2->data[i]);
        if (ret==-1){
            if (list_insert(L1,L2->data[i],L1->last+1)==-1){
                return -1;
            }
        }
        i++;
    }
    return 0;
}

/*
    10、删除元素中的重复数据
*/
int list_purge(sqlink L){
    int i;
    int j;

    if (L->last==0)
        return 0;

    i = 1;

    while (i<=L->last){
        j = i - 1;
        while (j>=0){
            if (L->data[i]==L->data[j]){
                list_delete(L, i);
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
}

/*
    11、销毁-内存释放
*/
int list_free(sqlink L){
    if (L==NULL)
        return -1;
    free(L);
    L = NULL;
    return 0;
}

int main(int argc, char const *argv[]){
    sqlink L;

    L = list_create();
    if (L==NULL)
        return -1;


    list_insert(L, 12, 0);
    list_insert(L, 13, 0);
    list_insert(L, 14, 0);
    list_show(L);
    puts("");

    printf("线性表的长度为：%d", list_length(L));
    puts("");

    printf("这个值的下标为：%d",list_locate(L,12));
    puts("");

    printf("列表是否为空：%d", list_empty(L));
    puts("");

    printf("删除……\n");
    list_delete(L, 1);
    list_show(L);

    list_clear(L);
    list_show(L);

    puts("");
    sqlink L1,L2;
    L1 = list_create();
    if (L1==NULL)
        return -1;
    L2 = list_create();
    if (L2==NULL)
        return -1;

    list_insert(L1, 12, 0);
    list_insert(L1, 13, 0);
    list_insert(L1, 14, 0);
    list_insert(L2, 12, 0);
    list_insert(L2, 15, 0);
    list_insert(L2, 17, 0);
    list_show(L1);
    list_show(L2);
    list_merge(L1, L2);
    list_show(L1);

    printf("删除列表中的重复数据\n");
    sqlink L3;
    L3 = list_create();
    if (L3==NULL){
        printf("L3 is NULL\n");
        return -1;
    }
    list_insert(L3, 12, 0);
    list_insert(L3, 13, 0);
    list_insert(L3, 12, 0);
    list_insert(L3, 14, 0);
    list_show(L3);
    puts("删除重复数据后：");
    list_purge(L3);
    list_show(L3);

    list_free(L);
    list_free(L1);
    list_free(L2);
    list_free(L3);

    return 0;
}
