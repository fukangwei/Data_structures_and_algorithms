#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct {
    ElemType data[MAXSIZE]; /* 数组，用于存储数据元素，长度为MAXSIZE */
    int length;             /* 线性表当前长度                      */
} SqList;

SqList Init() { /* 顺序表的初始化 */
    /* 构造一个空的线性表L，时间复杂度O(1) */
    SqList L;     /* 定义一个顺序表  */
    L.length = 0; /* 顺序表的长度为0 */
    return L;     /* 返回空顺序表    */
}

SqList Create ( SqList L ) { /* 顺序表的建立 */
    int i;
    srand ( ( unsigned ) time ( NULL ) );

    for ( i = 0; i < 10; i++ ) {
        L.data[i] = rand() % 100;
        L.length++;
    }

    return L;
}

/* 初始条件：顺序线性表L已存在，1 ≤ i ≤ ListLength(L)                         */
/* 操作结果：用e返回L中第i个数据元素的值，注意i是指位置，第1个位置的数组是从0开始 */
ElemType GetElem ( SqList L, int i ) {
    if ( i < 1 || i > L.length ) { /* 检查查询位置是否合法 */
        printf ( "查找位置错误！\n" );
        return 0;
    } else {
        return L.data[i - 1];
    }
}

SqList SqListInsert ( SqList L, int i, ElemType x ) { /* 在顺序表中的第i个位置插入元素x */
    if ( L.length == MAXSIZE ) { /* 插入时，必须检查表是否已经满了，否则会出现溢出错误 */
        printf ( "表已经满了\n" );
    } else if ( i < 1 || i > L.length ) { /* 判断插入位置的有效性 */
        printf ( "插入位置错误\n" );
    }

    int j;

    for ( j = L.length - 1; j >= i - 1; j-- ) { /* 将第i个位置之后的元素后移 */
        L.data[j + 1] = L.data[j];
    }

    L.data[i - 1] = x; /* 插入元素x */
    L.length++; /* 顺序表长度增1 */
    return L;
}

SqList SqListDelete ( SqList L, int i ) { /* 删除顺序表中的第i个位置的元素 */
    if ( i < 1 || i > L.length ) { /* 检查删除位置是否合法 */
        printf ( "删除位置错误\n" );
    }

    int j;

    for ( j = i - 1; j < L.length; j++ ) {
        L.data[j] = L.data[j + 1]; /* 将第i个位置之后的元素前移 */
    }

    L.length--; /* 顺序表长度减1 */
    return L;
}

int main() {
    SqList nmList;
    nmList = Init();
    nmList = Create ( nmList );
    int find;
    int found;
    int pos;
    ElemType value;
    char opp;
    int i;
    printf ( "顺序表初始化为：" );

    for ( i = 0; i < nmList.length; i++ ) {
        printf ( "%d ", nmList.data[i] );
    }

    printf ( "\n1.查看顺序表 \n2.查找 \n3.插入 \n4.删除 \n0.退出 \n请选择你的操作：\n" );

    while ( opp != '0' ) {
        scanf ( "%c", &opp );

        switch ( opp ) {
            case '1':
                printf ( "\n查看顺序表：" );

                for ( i = 0; i < nmList.length; i++ ) {
                    printf ( "%d ", nmList.data[i] );
                }

                printf ( "\n" );
                break;
            case '2':
                printf ( "\n进入查找功能，请问需要查找第几个元素：" );
                scanf ( "%d", &find );
                found = GetElem ( nmList, find );
                printf ( "第%d个值为%d ", find, found );
                printf ( "\n" );
                break;
            case '3':
                printf ( "进入插入功能，请输入插入元素位置：" );
                scanf ( "%d", &pos );
                printf ( "请输入插入元素的值：" );
                scanf ( "%d", &value );
                nmList = SqListInsert ( nmList, pos, value );
                printf ( "\n插入元素后顺序表为：" );

                for ( i = 0; i < nmList.length; i++ ) {
                    printf ( "%d ", nmList.data[i] );
                }

                printf ( "\n" );
                break;
            case '4':
                printf ( "进入删除功能，请输入删除元素位置：" );
                scanf ( "%d", &pos );
                nmList = SqListDelete ( nmList, pos );
                printf ( "\n删除元素后顺序表为：" );

                for ( i = 0; i < nmList.length; i++ ) {
                    printf ( "%d ", nmList.data[i] );
                }

                printf ( "\n" );
                break;
            case '0':
                exit ( 0 );
        }
    }
}