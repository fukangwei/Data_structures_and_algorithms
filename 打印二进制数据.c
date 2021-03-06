#include <stdio.h>

char* my_itoa ( int num, char* str, int radix ) {
    char index[] = "0123456789ABCDEF"; /* 索引表 */
    unsigned unum; /* 中间变量 */
    int i = 0, j, k;

    /* 确定unum的值 */
    if ( radix == 10 && num < 0 ) { /* 十进制负数 */
        unum = ( unsigned ) - num;
        str[i++] = '-';
    } else {
        unum = ( unsigned ) num; /* 其他情况 */
    }

    do { /* 转换 */
        str[i++] = index[unum % ( unsigned ) radix];
        unum /= radix;
    } while ( unum );

    str[i] = '\0';

    /* 逆序 */
    if ( str[0] == '-' ) {
        k = 1; /* 十进制负数 */
    } else {
        k = 0;
    }

    char temp;

    for ( j = k; j <= ( i - 1 ) / 2; j++ ) {
        temp = str[j];
        str[j] = str[i - 1 + k - j];
        str[i - 1 + k - j] = temp;
    }

    return str;
}

int main ( void ) {
    int number = 15;
    char string[25] = { 0 };
    my_itoa ( number, string, 2 );
    printf ( "integer = %d, string = %s\n", number, string );
    return 0;
}