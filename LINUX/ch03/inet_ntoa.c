#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(){
    struct sockaddr_in addr1, addr2;
    char *str_ptr;
    char str_arr[20];

    addr1.sin_addr.s_addr = htonl(0X1020304);
    addr2.sin_addr.s_addr = htonl(0x1010101);

    str_ptr = inet_ntoa(addr1.sin_addr);
    strcpy(str_arr, str_ptr);
    printf("Dotted_decimal notatation1:%s \n", str_ptr);

    inet_ntoa(addr2.sin_addr);
    printf("Dotted_decimal notatation1:%s \n", str_ptr);

    printf("Dotted_decimal notatation1:%s \n", str_arr);

    return 0;
}