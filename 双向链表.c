#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line * prior;
    int data;
    struct line * next;
} line;

line* initLine ( line * head ); /* 双向链表的创建 */
line * insertLine ( line * head, int data, int add ); /* 插入元素，add表示插入位置 */
line * delLine ( line * head, int data ); /* 删除指定元素 */
int selectElem ( line * head, int elem ); /* 查找指定元素 */
line *amendElem ( line * p, int add, int newElem ); /* 更改指定位置节点中存储的数据，add表示更改位置 */
void display ( line * head ); /* 输出双向链表的数据 */

int main() {
    line * head = NULL;
    head = initLine ( head ); /* 创建双向链表 */
    display ( head );
    head = insertLine ( head, 7, 3 ); /* 在第3个位置插入元素7 */
    display ( head );
    head = delLine ( head, 2 ); /* 删除元素2 */
    display ( head );
    printf ( "元素3的位置是：%d\n", selectElem ( head, 3 ) );
    head = amendElem ( head, 3, 6 ); /* 将第3个节点中的数据改为存储6 */
    display ( head );
    return 0;
}

line * initLine ( line * head ) {
    head = ( line* ) malloc ( sizeof ( line ) );
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line * list = head;

    for ( int i = 2; i <= 5; i++ ) {
        line * body = ( line* ) malloc ( sizeof ( line ) );
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;
        list = list->next;
    }

    return head;
}

line * insertLine ( line * head, int data, int add ) {
    /* 新建数据域为data的结点 */
    line * temp = ( line* ) malloc ( sizeof ( line ) );
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;

    if ( add == 1 ) { /* 插入到链表头，要特殊考虑 */
        temp->next = head;
        head->prior = temp;
        head = temp;
    } else {
        line * body = head;

        for ( int i = 1; i < add - 1; i++ ) { /* 找到要插入位置的前一个结点 */
            body = body->next;
        }

        if ( body->next == NULL ) { /* 判断条件为真，说明插入位置为链表尾 */
            body->next = temp;
            temp->prior = body;
        } else {
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
    }

    return head;
}

line * delLine ( line * head, int data ) {
    line * temp = head;

    while ( temp ) { /* 遍历链表 */
        /* 判断当前结点中数据域和data是否相等，若相等，则摘除该结点 */
        if ( temp->data == data ) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free ( temp );
            return head;
        }

        temp = temp->next;
    }

    printf ( "链表中无该数据元素\n" );
    return head;
}

int selectElem ( line * head, int elem ) {
    line * t = head; /* 新建一个指针t，初始化为头指针head */
    int i = 1;

    while ( t ) {
        if ( t->data == elem ) {
            return i;
        }

        i++;
        t = t->next;
    }

    return -1; /* 程序执行至此处，表示查找失败 */
}

line *amendElem ( line * p, int add, int newElem ) {
    line * temp = p;

    for ( int i = 1; i < add; i++ ) { /* 遍历到被删除结点 */
        temp = temp->next;
    }

    temp->data = newElem;
    return p;
}

void display ( line * head ) {
    line * temp = head;

    while ( temp ) {
        if ( temp->next == NULL ) {
            printf ( "%d\n", temp->data );
        } else {
            printf ( "%d->", temp->data );
        }

        temp = temp->next;
    }
}