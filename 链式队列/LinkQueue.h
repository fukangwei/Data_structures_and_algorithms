#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef int ElemType; /* 队列的数据类型 */

typedef struct node {
    ElemType data; /* 队列的数据类型 */
    struct node *next; /* 指向下一个结点 */
} QueNode, *QuePtr;

typedef struct {
    QuePtr front; /* 指向队头的指针 */
    QuePtr rear; /* 指向队尾的指针 */
} LinkQueue;

void InitQueue ( LinkQueue *q ); /* 初始化队列 */
void CreateQueue ( LinkQueue *q ); /* 创建队列 */
void EnQueue ( LinkQueue *q, ElemType e ); /* 进队操作，将元素e压入队列中 */
void DeQueue ( LinkQueue *q, ElemType *e ); /* 出队操作，将出队的元素存入“*e”中 */
int GetQueueLength ( LinkQueue *q ); /* 获取队列的长度 */
void Print ( LinkQueue *q ); /* 打印队列的元素 */
void Clear ( LinkQueue *q ); /* 清空队列 */
void TopQueue ( LinkQueue *q, ElemType *e ); /* 返回队头的元素 */

#endif