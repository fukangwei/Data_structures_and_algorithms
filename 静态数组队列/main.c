#include "queue.h"
#include "stdio.h"
#include "assert.h"

#define QUEUE_SIZE 5 /* 队列中元素的最大数量 */
#define ARRAY_SIZE (QUEUE_SIZE + 1) /* 数组的长度 */

/* 用于存储队列元素的数组，以及指向队列头和尾的指针 */
static QUEUE_TYPE queue[QUEUE_SIZE];
static size_t front = 1;
static size_t rear = 0;
static size_t queue_size = 0; /* 队列中有效数据的数量 */

void insert ( QUEUE_TYPE value ) {
    assert ( !is_full() );
    rear = ( rear + 1 ) % ARRAY_SIZE;
    queue[rear] = value;
    queue_size++;
}

void delete ( void ) {
    assert ( !is_empty() );
    front = ( front + 1 ) % ARRAY_SIZE;
    queue_size--;
}

QUEUE_TYPE first ( void ) {
    assert ( !is_empty() );
    return queue[front];
}

int is_empty ( void ) {
    return ( rear + 1 ) % ARRAY_SIZE == front;
}

int is_full ( void ) {
    return ( rear + 2 ) % ARRAY_SIZE == front;
}

void print ( void ) {
    int index = 0;

    for ( ; index <= QUEUE_SIZE; index++ ) {
        printf ( "%d ", queue[index] );
    }

    printf ( "front is %d, rear is %d\n", front, rear );

    for ( index = 0; index < queue_size; index++ ) {
        printf ( "%d ", queue[ ( front + index ) % ARRAY_SIZE] );
    }

    printf ( "\n" );
}

int main ( void ) {
    insert ( 1 );
    insert ( 2 );
    insert ( 3 );
    insert ( 4 );
    print();
    delete();
    delete();
    print();
    insert ( 5 );
    insert ( 6 );
    insert ( 7 );
    print();
    return 0;
}