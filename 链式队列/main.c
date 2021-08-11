#include "LinkQueue.h"
#include <stdio.h>

int main() {
    LinkQueue q;
    CreateQueue ( &q );
    Print ( &q );
    int top;
    TopQueue ( &q, &top );
    printf ( "队头的元素为：%d\n", top );
    int len = GetQueueLength ( &q );
    int k;
    printf ( "将队列中的所有元素出队：\n" );

    for ( int i = 0; i < len; ++i ) {
        DeQueue ( &q, &k );
        printf ( "%d ", k );
    }

    printf ( "\n" );
    Clear ( &q );
    return 0;
}