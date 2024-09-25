#include <stdio.h>
#include "linkqueue.h"

int main(int argc, char const *argv[]){
    linkqueue *lq;

    lq = queue_create();
    if (lq==NULL)
        return -1;

    enqueue(lq, 10);
    enqueue(lq, 20);
    enqueue(lq, 30);
    enqueue(lq, 40);

    queue_clear(lq);

#if 0
    while (!queue_empty(lq)){
        printf("dequeue:%d\n", dequeue(lq));
    }
#endif

    lq = queue_free(lq);
    enqueue(lq, 45);

    return 0;
}
