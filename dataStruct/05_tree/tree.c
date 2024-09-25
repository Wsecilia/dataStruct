#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/**
 * 1、创建;
 */
bitree *tree_create(){
    data_t ch;
    bitree *r;

    scanf("%c", &ch);
    if (ch == '#')
        return NULL;

    if ((r=(bitree*)malloc(sizeof(bitree)))==NULL){
        printf("malloc bitree failed!!\n");
        return NULL;
    }

    r->data = ch;

    //递归
    r->left = tree_create();
    r->right = tree_create();

    return r;
}

/**
 * 2、先序遍历:根→左→右;
 */
void preorder(bitree *r){
    if (r==NULL){
        return;
    }
    printf("%c", r->data); // 根;
    preorder(r->left);
    preorder(r->right);
}

/**
 * 3、中序遍历:左→根→右;
 */
void inorder(bitree *r){
    if (r==NULL){
        return;
    }
    inorder(r->left);
    printf("%c", r->data);
    inorder(r->right);
}       

/**
 * 4、后续遍历:左→右→根;
 */
void postorder(bitree *r){
    if (r==NULL){
        return;
    }
    postorder(r->left);
    postorder(r->right);
    printf("%c", r->data);
}     