#include <stdio.h>
#include <stdlib.h>

// 定义链表结点结构体
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// 创建带头结点的单链表
ListNode* createList() {
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    int num;
    while (scanf("%d", &num) && num != -1) {
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = num;
        newNode->next = NULL;
        ListNode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// 遍历单链表并输出结果
void printList(ListNode *head) {
    ListNode *temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 删除单链表中数据域值与输入的整数值相等的结点
void deleteNode(ListNode *head, int value) {
    ListNode *temp = head;
    while (temp->next != NULL) {
        if (temp->next->data == value) {
            ListNode *toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

// 直接插入排序算法对单链表进行排序
void insertionSortList(ListNode *head) {
    ListNode *p = head->next;
    while (p != NULL) {
        ListNode *q = head;
        ListNode *r = head->next;
        while (r != NULL && r->data < p->data) {
            q = r;
            r = r->next;
        }
        ListNode *temp = p->next;
        p->next = r;
        q->next = p;
        p = temp;
    }
}

int main() {
    printf("请输入一组整数，以-1结束：\n");
    ListNode *head = createList();
    printf("原始链表：");
    printList(head);

    int valueToDelete;
    printf("请输入要删除的整数：");
    scanf("%d", &valueToDelete);
    deleteNode(head, valueToDelete);
    printf("删除后的链表：");
    printList(head);

    insertionSortList(head);
    printf("排序后的链表：");
    printList(head);

    // 释放链表内存
    ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}