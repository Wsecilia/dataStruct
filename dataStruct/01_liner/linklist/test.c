#include <stdio.h>
#include "linklist.h"

void test_get();
void test_insert();
void test_delete();

int main(int argc, char const *argv[]){
    linklist H;
    int value;

    H = list_create();
    if (H==NULL)
        return -1;

    printf("请输入要插入的数值：");
    while(1){
        scanf("%d", &value);
        if (value==-1)
            break;
        list_tail_insert(H,value);
        printf("请输入要插入的数值：");
    }

    list_show(H);
    list_reverse(H);
    list_show(H);

    /*链表释放*/
    H=list_free(H);
    
    /*链表删除
    test_delete();
    */

    /*链表查找
    test_get();
    */

    /*链表插入
    test_insert();
    */

    return 0;
}

void test_get(){
    linklist H;
    int value;
    linklist p;

    H = list_create();
    if (H==NULL)
        printf("H is NULL"); //根据位置选择输出

    printf("请输入要插入的数值：");
    while(1){
        scanf("%d", &value);
        if (value==-1)
            break;
        list_tail_insert(H,value);
        printf("请输入要插入的数值：");
    }

    list_show(H);

    p = list_get(H, 2);
    if (p!=NULL)
        printf("the value is %d ", p->data);
}


void test_insert(){
    linklist H;
    int value;

    H = list_create();
    if (H==NULL)
        return;

    printf("请输入要插入的数值：");
    while(1){
        scanf("%d", &value);
        if (value==-1)
            break;
        list_tail_insert(H,value);
        printf("请输入要插入的数值：");
    }

    list_show(H);

    // 链表插入
    list_insert(H, 88,2);
    list_show(H);

}

void test_delete(){
    linklist H;
    int value;

    H = list_create();
    if (H==NULL)
        return;

    printf("请输入要插入的数值：");
    while(1){
        scanf("%d", &value);
        if (value==-1)
            break;
        list_tail_insert(H,value);
        printf("请输入要插入的数值：");
    }

    list_show(H);

    //链表删除
    list_delete(H, 2);
    list_show(H);
    //链表释放
    H=list_free(H);
    printf("%p\n", H);
}