/*
 * Mathi C Library - Networking Implementation
 * 
 * TCP and UDP networking functions for connecting, sending, and receiving data.
 * 
 * Status codes:
 * Return values are the same as the underlying socket functions or -1 on error.
 * 
 * @file networking.c
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. See http://opensource.org/licenses/MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

/* --- TCP --- */

/**
 * @brief Establish a TCP connection to a host and port.
 * @param host Hostname or IP address
 * @param port TCP port
 * @return Socket descriptor on success, -1 on error
 */
int connect_tcp(const char *host, int port);

/**
 * @brief Send data over a TCP connection.
 * @param sock TCP socket descriptor
 * @param data Buffer containing data to send
 * @param size Size of data in bytes
 * @return Number of bytes sent, or -1 on error
 */
int send_tcp(int sock, const char *data, size_t size);

/**
 * @brief Receive data from a TCP connection.
 * @param sock TCP socket descriptor
 * @param buffer Buffer to store received data
 * @param size Maximum number of bytes to receive
 * @return Number of bytes received, or -1 on error
 */
int recv_tcp(int sock, char *buffer, size_t size);

/* --- UDP --- */

/**
 * @brief Create a UDP socket.
 * @param host Ignored (UDP is connectionless)
 * @param port Ignored (UDP is connectionless)
 * @return Socket descriptor on success, -1 on error
 */
int connect_udp(const char *host, int port);

/**
 * @brief Send data over UDP.
 * @param sock UDP socket descriptor
 * @param data Buffer containing data to send
 * @param size Size of data in bytes
 * @param host Destination host
 * @param port Destination port
 * @return Number of bytes sent, or -1 on error
 */
int send_udp(int sock, const char *data, size_t size, const char *host, int port);

/**
 * @brief Receive data over UDP.
 * @param sock UDP socket descriptor
 * @param buffer Buffer to store received data
 * @param size Maximum number of bytes to receive
 * @return Number of bytes received, or -1 on error
 */
int recv_udp(int sock, char *buffer, size_t size);