/*
 * Mathi C Library - Networking Implementation
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#include "mathi/networking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int connect_tcp(const char *host, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return -1;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    struct hostent *he = gethostbyname(host);
    if (!he) { close(sock); return -1; }
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(sock);
        return -1;
    }
    return sock;
}

int send_tcp(int sock, const char *data, size_t size) {
    return send(sock, data, size, 0);
}

int recv_tcp(int sock, char *buffer, size_t size) {
    return recv(sock, buffer, size, 0);
}

int connect_udp(const char *host, int port) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) return -1;
    return sock;
}

int send_udp(int sock, const char *data, size_t size, const char *host, int port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    struct hostent *he = gethostbyname(host);
    if (!he) return -1;
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);

    return sendto(sock, data, size, 0, (struct sockaddr *)&addr, sizeof(addr));
}

int recv_udp(int sock, char *buffer, size_t size) {
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    return recvfrom(sock, buffer, size, 0, (struct sockaddr *)&addr, &len);
}