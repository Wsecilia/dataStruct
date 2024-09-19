#include <stdio.h>
#include "sqlist.h"

void test_insert();
void test_delete();
void test_merge();
void test_purge();

int main(){
    //test_insert(); // 测试插入
    //test_delete(); // 测试删除某元素
    //test_merge(); // 合并两个线性表
    test_purge(); // 去掉线性表里的重复数据

    return 0;
}

void test_insert(){
    sqlink L;
    //创建线性表
    L = list_create();
    if(L==NULL)
        return;
    //插入
    for (int i = 0; i < 6; i++){
        list_insert(L, 10 + i, 0);
    }
    //展示 
    list_show(L);
    list_insert(L, 23, 2);
    list_show(L);
    list_insert(L, 100, list_length(L));//放在最后一位
    list_show(L);
    //越界
    //list_insert(L, 190, 7);
    list_free(L);
}

void test_delete(){
    sqlink L;
    L = list_create();
    if(L==NULL)
        return;
    //插入
    for (int i = 0; i < 6; i++){
        list_insert(L, 10 + i, 0);
    }
    //展示 
    list_show(L);
    //list_delete(L, 0);//删除第一个
    //list_delete(L, L->last);//删除最后一个
    list_delete(L, L->last+1);//超范围，不会删除
    list_show(L);
    list_free(L);
}

void test_merge(){
    sqlink L1,L2;

    L1 = list_create();
    if(L1==NULL)
        return;

    L2 = list_create();
    if(L2==NULL)
        return;
    
    list_insert(L1, 10, 0);
    list_insert(L1, 20, 0);
    list_insert(L1, 30, 0);
    list_insert(L1, 40, 0);

    list_insert(L2, 50, 0);
    list_insert(L2, 10, 0);
    list_insert(L2, 90, 0);
    list_show(L1);
    list_show(L2);
    
    list_merge(L1, L2);
    printf("----- 合并后 -----\n");
    list_show(L1);
}

void test_purge(){
    sqlink L;

    L = list_create();
    if(L==NULL)
        return;
    
    list_insert(L, 10, 0);
    list_insert(L, 20, 0);
    list_insert(L, 30, 0);
    list_insert(L, 40, 0);
    list_insert(L, 20, 0);
    list_insert(L, 10, 0);
    list_show(L);

    list_purge(L);
    printf("----- 删除重复元素后 -----\n");
    list_show(L);

}