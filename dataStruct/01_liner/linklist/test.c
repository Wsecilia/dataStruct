#include <stdio.h>
#include "linklist.h"

void test_get();
void test_insert();
void test_delete();
void test_reverse();
void test_adjmax();

int main(int argc, char const *argv[]){
    
    linklist H1,H2;
    int a[]={1,4,5,7,9};
    int b[]={2,4,6,8,10};
    int i;

    H1 = list_create();
    if (H1==NULL)
        return -1;

    H2 = list_create();
    if (H2==NULL)
        return -1;

    for ( i = 0; i < sizeof(a)/sizeof(int); i++){
        list_tail_insert(H1, a[i]);
    }

    for ( i = 0; i < sizeof(b)/sizeof(int); i++){
        list_tail_insert(H2, b[i]);
    }

    list_show(H1);
    list_show(H2);
    list_merge(H1, H2);
    printf("merge:\n");
    list_show(H1);

    list_free(H1);
    list_free(H2);

    /*链表释放*/
   // list_free(H);

    /*链表求两和最大的第一个结点
    test_adjmax();
    */

    /*链表倒置
    test_reverse();
    */
    
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

void test_reverse(){
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
    list_reverse(H);
    list_show(H);

    list_free(H);
}

void test_adjmax(){
    linklist H;
    linklist r;
    int value;
    int sum;

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
    r = list_adjmax(H,&sum);
    if (r!=NULL&&r!=H){
        printf("data=%d,最大和为：%d\n", r->data,sum);
    }
}