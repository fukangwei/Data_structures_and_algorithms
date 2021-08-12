#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define portnumber 3333

int main ( int argc, char *argv[] ) {
    int sockfd, new_fd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int sin_size;
    char hello[] = "Hello! Are You Fine?\n";

    /* 服务器端开始建立sockfd描述符 */
    /* AF_INET：IPV4；SOCK_STREAM：TCP */
    if ( ( sockfd = socket ( AF_INET, SOCK_STREAM, 0 ) ) == -1 ) {
        fprintf ( stderr, "Socket error:%s\n\a", strerror ( errno ) );
        exit ( 1 );
    }

    /* 服务器端填充sockaddr结构 */
    bzero ( &server_addr, sizeof ( struct sockaddr_in ) ); /* 初始化，置0 */
    server_addr.sin_family = AF_INET; /* Internet */
    /* (将本机器上的long数据转化为网络上的long数据)和任何主机通信，
       INADDR_ANY表示可以接收任意IP地址的数据，即绑定到所有的IP */
    server_addr.sin_addr.s_addr = htonl ( INADDR_ANY );
    /* (将本机器上的short数据转化为网络上的short数据)端口号 */
    server_addr.sin_port = htons ( portnumber );

    /* 捆绑sockfd描述符到IP地址 */
    if ( bind ( sockfd, ( struct sockaddr * ) ( &server_addr ), sizeof ( struct sockaddr ) ) == -1 ) {
        fprintf ( stderr, "Bind error:%s\n\a", strerror ( errno ) );
        exit ( 1 );
    }

    if ( listen ( sockfd, 5 ) == -1 ) { /* 设置允许连接的最大客户端数 */
        fprintf ( stderr, "Listen error:%s\n\a", strerror ( errno ) );
        exit ( 1 );
    }

    while ( 1 ) {
        sin_size = sizeof ( struct sockaddr_in );

        /* 服务器阻塞，直到客户程序建立连接 */
        if ( ( new_fd = accept ( sockfd, ( struct sockaddr * ) ( &client_addr ), &sin_size ) ) == -1 ) {
            fprintf ( stderr, "Accept error:%s\n\a", strerror ( errno ) );
            exit ( 1 );
        }

        /* 将网络地址转换成“.”字符串格式 */
        fprintf ( stderr, "Server get connection from %s\n", inet_ntoa ( client_addr.sin_addr ) );

        if ( write ( new_fd, hello, strlen ( hello ) ) == -1 ) {
            fprintf ( stderr, "Write Error:%s\n", strerror ( errno ) );
            exit ( 1 );
        }

        close ( new_fd ); /* 这个通讯已经结束 */
        /* 循环下一个 */
    }

    close ( sockfd ); /* 结束通讯 */
    exit ( 0 );
}