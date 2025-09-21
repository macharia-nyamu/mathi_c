/*
 * Mathi C Library - Networking Utilities
 * networking.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_NETWORKING_H
#define MATHI_NETWORKING_H

#include <stddef.h>

/**
 * @file mathi/networking.h
 * @brief Basic TCP and UDP networking functions.
 */


/**
 * @brief Establish a TCP connection to a host and port.
 * @param host Hostname or IP address
 * @param port Port number
 * @return Socket descriptor on success, -1 on failure
 */
int mathi_connect_tcp(const char *host, int port);

/**
 * @brief Send data over a TCP connection.
 * @param sock Socket descriptor
 * @param data Pointer to data buffer
 * @param size Size of data in bytes
 * @return Number of bytes sent, or -1 on error
 */
int mathi_send_tcp(int sock, const char *data, size_t size);

/**
 * @brief Receive data from a TCP connection.
 * @param sock Socket descriptor
 * @param buffer Buffer to store received data
 * @param size Maximum number of bytes to receive
 * @return Number of bytes received, or -1 on error
 */
int mathi_recv_tcp(int sock, char *buffer, size_t size);


/**
 * @brief Create a UDP socket.
 * @param host Hostname or IP (unused in socket creation, provided for consistency)
 * @param port Port number (unused in socket creation, provided for consistency)
 * @return Socket descriptor on success, -1 on failure
 */
int mathi_connect_udp(const char *host, int port);

/**
 * @brief Send data over a UDP socket to a specific host and port.
 * @param sock UDP socket descriptor
 * @param data Data buffer to send
 * @param size Size of data in bytes
 * @param host Destination hostname or IP
 * @param port Destination port
 * @return Number of bytes sent, or -1 on error
 */
int mathi_send_udp(int sock, const char *data, size_t size, const char *host, int port);

/**
 * @brief Receive data from a UDP socket.
 * @param sock UDP socket descriptor
 * @param buffer Buffer to store received data
 * @param size Maximum number of bytes to receive
 * @return Number of bytes received, or -1 on error
 */
int mathi_recv_udp(int sock, char *buffer, size_t size);

#endif // MATHI_NETWORKING_H