/*
* Mathi C Library - networking_test_verbose.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "mathi/networking.h"

void test_tcp_connect()
{
    printf("Test: TCP Connect\n");

    int sock = mathi_connect_tcp("example.com", 80);
    if(sock >= 0)
    {
        printf("TCP connection successful! Socket FD = %d\n", sock);
        close(sock);
    }
    else
    {
        printf("TCP connection failed: %s\n", strerror(errno));
    }
}

void test_udp_socket()
{
    printf("\nTest: UDP Socket\n");

    int udp_sock = mathi_connect_udp("0.0.0.0", 0);
    if(udp_sock >= 0)
    {
        printf("UDP socket successfully created! Socket FD = %d\n", udp_sock);
        close(udp_sock);
    }
    else
    {
        printf("UDP socket creation failed: %s\n", strerror(errno));
    }
}

int main()
{
    test_tcp_connect();
    test_udp_socket();

    printf("\nAll networking tests completed.\n");
    return 0;
}