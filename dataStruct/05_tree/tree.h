typedef char data_t;

typedef struct node_t{
    data_t data; // 存储节点的数据;
    struct node_t *left; // 指向左子节点的指针;
    struct node_t *right; // 指向右子节点的指针;
}bitree;

bitree *tree_create(); // 创建;
void preorder(bitree *r);       // 先序遍历;
void inorder(bitree *r);         // 中序遍历;
void postorder(bitree *r);       // 后续遍历;