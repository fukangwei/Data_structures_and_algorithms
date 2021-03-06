/* 返回T在S中第pos个字符后出现的位置；否则函数返回0 */
int StrIndex ( char *S, char *T, int pos ) {
    int i = pos - 1, j = 0, lenS, lenT, b = 0;
    lenS = strlen ( S );
    lenT = strlen ( T );

    while ( i < lenS && j < lenT ) {
        /* 当前对应字符相同，继续比较后面的字符 */
        if ( * ( S + i ) == * ( T + j ) ) {
            i++;
            j++;
        } else { /* 重新进行新的一趟比较 */
            i = i - j + 1;
            j = 0;
        }
    }

    if ( j == lenT ) {
        return ( i - lenT + 1 );
    } else {
        return 0;
    }
}