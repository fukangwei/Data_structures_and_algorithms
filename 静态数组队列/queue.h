#ifndef QUEUE_H
#define QUEUE_H

#include "stdlib.h"

#define QUEUE_TYPE int /* 队列元素的类型 */

void create_queue ( size_t size );
void destroy_queue ( void );
void insert ( QUEUE_TYPE value );
void delete ( void ); /* 从队列中移除一个元素并将其丢弃 */
QUEUE_TYPE first ( void ); /* 返回队列中的第一个元素的值，但不修改队列本身 */
int is_empty ( void ); /* 如果队列为空，返回TRUE */
int is_full ( void ); /* 如果队列已满，返回TRUE，否则返回FALSE */

#endif