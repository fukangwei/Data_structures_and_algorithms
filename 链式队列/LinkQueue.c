#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

void InitQueue ( LinkQueue *q ) {
    /* 初始化队头与队尾的指针指向头结点 */
    q->front = q->rear = ( QuePtr ) malloc ( sizeof ( QueNode ) );
    q->front->next = NULL;
}

void CreateQueue ( LinkQueue *q ) {
    InitQueue ( q );
    printf ( "请输入要进队的元素，以CTRL + Z结尾\n" );
    int k;

    while ( ( scanf ( "%d", &k ) ) != EOF ) {
        EnQueue ( q, k );
    }
}

void EnQueue ( LinkQueue *q, ElemType e ) {
    QuePtr temp = ( QuePtr ) malloc ( sizeof ( QueNode ) ); /* 创建新结点 */

    if ( temp ) { /* 如果内存分配成功 */
        temp->data = e; /* 初始化新结点的数据为e */
        temp->next = NULL; /* 队列只能从队尾插入所以下一个结点初始化为NULL */
        /* 将队尾结点的指针指向新结点，如果新结点为第一个
           结点，则q->rear->next相当于q->front->next */
        q->rear->next = temp;
        q->rear = temp; /* 将指向队尾的指针指向新结点 */
    }
}

void DeQueue ( LinkQueue *q, ElemType *e ) {
    if ( q->front == q->rear ) { /* 队列为空 */
        return;
    }

    QuePtr temp = q->front->next; /* 初始化temp为要出队的结点的指针 */

    /* 如果要出队的结点为最后一个结点，使q->rear指向头结点防止出现悬空的指针 */
    if ( q->front->next == q->rear ) {
        q->rear = q->front;
    }

    *e = temp->data; /* 将出队的数据元素存入*e */
    q->front->next = temp->next; /* 使下一个结点成为队头，如果没有下一个结点则为NULL */
    free ( temp ); /* 删除要出队的结点 */
}

bool IsEmpty ( LinkQueue *q ) {
    if ( q->front == q->rear ) {
        return true;
    }

    return false;
}

int GetQueueLength ( LinkQueue *q ) {
    QuePtr temp = q->front;
    int i = 0;

    while ( temp != q->rear ) {
        ++i;
        temp = temp->next;
    }

    return i;
}

void Clear ( LinkQueue *q ) {
    QuePtr temp = q->front->next;

    while ( temp ) {
        QuePtr tp = temp;
        temp = temp->next;
        free ( tp );
    }

    temp = q->front;
    q->front = q->rear = NULL;
    free ( temp );
}

void Print ( LinkQueue *q ) {
    if ( q->front == q->rear ) {
        return;
    }

    QuePtr temp = q->front->next;

    while ( temp != q->rear ) {
        printf ( "%d ", temp->data );
        temp = temp->next;
    }

    printf ( "%d", temp->data );
    printf ( "\n" );
}

void TopQueue ( LinkQueue *q, ElemType *e ) {
    if ( q->front == q->rear ) {
        return;
    }

    *e = q->front->next->data;
}