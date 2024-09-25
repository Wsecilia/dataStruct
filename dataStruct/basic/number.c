#include <stdio.h>

#define ROWS 4
#define COLS 3

int main() {
    int studentId;
    int matrix4x3[ROWS][COLS];
    int matrix3x4[COLS][ROWS];
    printf("请输入你的考号: ");
    scanf("%d", &studentId);

    // 使用考号创建4x3矩阵
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix4x3[i][j] = studentId;
            printf("%d ", matrix4x3[i][j]);
        }
        printf("\n");
    }

    // 转置矩阵
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix3x4[j][i] = matrix4x3[i][j];
        }
    }

    // 输出3x4矩阵
    printf("转置后的3x4矩阵:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", matrix3x4[i][j]);
        }
        printf("\n");
    }

    return 0;
}