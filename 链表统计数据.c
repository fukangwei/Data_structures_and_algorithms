#include <stdio.h>
#include <stdlib.h>

int array[] = {1, 2, 5, 6, 5, 1, 4, 7, 9, 8, 7, 2, 2}; /* 插入的数据 */

typedef int ElemType;

typedef struct Node {
    ElemType addr;      /* 数据          */
    ElemType count_num; /* 数据出现的次数 */
    struct Node *next;
} LNode, *LinkList;

LinkList Find ( LinkList L, int x );

/* 建立一个带头结点的单链表，头插法 */
void Build ( LinkList L, int array[], int array_length ) {
    int n = array_length;
    LinkList q, p;
    /* 建立头结点 */
    L->next = NULL;
    L->addr = -1;

    while ( n ) { /* 向链表中插入数据 */
        int insert_num = array[array_length - n];
        p = Find ( L, insert_num ); /* 查找insert_num在链表中是否存在 */

        if ( p == NULL ) { /* 如果在链表中没有发现数据 */
            q = ( LinkList ) malloc ( sizeof ( LNode ) );
            q->addr = insert_num;
            q->count_num = 1;
            q->next = L->next;
            L->next = q;
        } else { /* 如果在链表中发现数据 */
            p->count_num++;
        }

        n--;
    }
}

/* 输出单链表中的信息 */
void Print ( LinkList L ) {
    int num = 0;
    LinkList p;
    p = L->next;

    while ( p ) {
        num++;
        printf ( "addr is %d\n", p->addr );
        printf ( "insert_num is %d\n", p->count_num );
        printf ( "------------------\n" );
        p = p->next;
    }

    printf ( "长度为：%d\n", num );
}

/* 在链表中查找对应的节点是否存在，
   如果不存在，则返回NULL；
   如果存在，则返回指向对应节点的指针 */
LinkList Find ( LinkList L, int x ) {
    LinkList p;
    p = L;

    while ( p->next && p->next->addr != x ) {
        p = p->next;
    }

    if ( p->next ) {
        return p->next;
    } else {
        return NULL;
    }
}

/* 销毁链表中的所有节点 */
void DestroyList ( LinkList L ) {
    if ( L == NULL ) {
        return;
    }

    LinkList p = NULL;

    while ( L != NULL ) {
        p = L->next;
        printf ( "销毁%d\n", L->addr );
        free ( L );
        L = p;
    }
}

int main () {
    LinkList L, p;
    L = ( LinkList ) malloc ( sizeof ( LNode ) );
    Build ( L, array, sizeof ( array ) / sizeof ( array[0] ) );
    Print ( L );
    DestroyList ( L );
    return 0;
}