#ifdef _HASH_
#define _HASH_
#define N 15

typedef int datatype;

struct node{
    datatype key;
    datatype value;
    struct *node next;
}listnode,*linklist;

typedef struct {
    listtnode[];
}hash;

hash *hash_create();

#endif