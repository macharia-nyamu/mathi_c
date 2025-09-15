#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "mathi/networking.h"

int main() {
    int sock = connect_tcp("example.com", 80);
    if(sock >= 0) {
        printf("TCP connect OK\n");
        close(sock);
    } else {
        printf("TCP connect failed: %s\n", strerror(errno));
    }

    int udp_sock = connect_udp("0.0.0.0", 0);
    if(udp_sock >= 0) {
        printf("UDP socket created OK\n");
        close(udp_sock);
    } else {
        printf("UDP socket creation failed: %s\n", strerror(errno));
    }

    return 0;
}