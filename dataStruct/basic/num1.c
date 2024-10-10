/*
    基本存储结构与算法：
    1）从键盘输入一组学生成绩（大于等于0且小于等于100的整数），采用单链表作为存储结构存储这组学生成绩。
    2）对这组学生成绩进行排序，要求按成绩从高到低的次序排序，并输出
    3）编写算法，统计不及格成绩个数，并输出
*/

#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct Node {
    int score;               // 学生成绩
    struct Node* next;      // 指向下一个节点的指针
} Node;

// 函数声明
Node* createNode(int score);
void insertScore(Node* head, int score);
void sortScores(Node* head);
void printScores(Node* head);
int countFailingScores(Node* head);

int main() {
    Node* head = NULL;  // 初始化链表头指针
    int score;

    // 输入成绩
    printf("请输入学生成绩（输入负数结束）：\n");
    while (1) {
        scanf("%d", &score);
        if (score < 0) break;  // 输入负数结束
        if (score >= 0 && score <= 100) {
            insertScore(&head, score);  // 插入成绩
        } else {
            printf("成绩必须在0到100之间，请重新输入。\n");
        }
    }

    // 排序并输出成绩
    sortScores(head);
    printf("\n排序后的成绩（高到低）：\n");
    printScores(head);

    // 统计不及格成绩
    int failingCount = countFailingScores(head);
    printf("\n不及格成绩个数：%d\n", failingCount);

    // 释放链表内存
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

// 创建新节点
Node* createNode(int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

// 将成绩插入链表
void insertScore(Node** head, int score) {
    Node* newNode = createNode(score);
    newNode->next = *head;  // 新节点指向当前头节点
    *head = newNode;        // 更新头节点
}

// 排序链表中的成绩（高到低）
void sortScores(Node* head) {
    if (head == NULL) return;

    Node* current;
    Node* nextNode;
    int temp;

    // 冒泡排序法
    for (current = head; current->next != NULL; current = current->next) {
        for (nextNode = current->next; nextNode != NULL; nextNode = nextNode->next) {
            if (current->score < nextNode->score) {  // 从高到低排序
                // 交换成绩
                temp = current->score;
                current->score = nextNode->score;
                nextNode->score = temp;
            }
        }
    }
}

// 输出链表中的成绩
void printScores(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->score);
        current = current->next;
    }
    printf("\n");
}

// 统计不及格成绩个数
int countFailingScores(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->score < 60) {  // 不及格成绩
            count++;
        }
        current = current->next;
    }
    return count;
}