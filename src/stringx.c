/*
* Mathi C Library - String Utilities
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Reverse a string in place.
 * @param str String to reverse.
 * @return Pointer to the reversed string.
 */
char *mathi_string_reverse(char *str)
{
    int len = strlen(str);
    for(int i = 0, j = len - 1; i < j; i++, j--) 
    {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
    return str;
}

/**
 * @brief Find the index of a character in a string.
 * @param str String to search.
 * @param c Character to find.
 * @return Index of the character, -1 if not found.
 */
int mathi_string_index_of(const char *str, char c)
{
    for(int i = 0; str[i]; i++) if(str[i] == c) return i;
    return -1;
}

/**
 * @brief Check if a string contains a character.
 * @param str String to search.
 * @param c Character to find.
 * @return 1 if character exists, 0 otherwise.
 */
int mathi_string_contains(const char *str, char c)
{
    return mathi_string_index_of(str, c) != -1;
}

/**
 * @brief Count occurrences of a character in a string.
 * @param str String to search.
 * @param c Character to count.
 * @return Number of occurrences.
 */
int mathi_string_count_char(const char *str, char c)
{
    int count = 0;
    for(int i = 0; str[i]; i++) if(str[i] == c) count++;
    return count;
}

/**
 * @brief Convert a string to uppercase in place.
 * @param str String to convert.
 * @return Pointer to the uppercase string.
 */
char *mathi_string_to_upper(char *str)
{
    for(int i = 0; str[i]; i++) str[i] = toupper(str[i]);
    return str;
}

/**
 * @brief Convert a string to lowercase in place.
 * @param str String to convert.
 * @return Pointer to the lowercase string.
 */
char *mathi_string_to_lower(char *str)
{
    for(int i = 0; str[i]; i++) str[i] = tolower(str[i]);
    return str;
}

/**
 * @brief Compute the length of a string.
 * @param str String to measure.
 * @return Number of characters in the string.
 */
int mathi_string_length(const char *str)
{
    int len = 0;
    while(str[len]) len++;
    return len;
}

/**
 * @brief Concatenate two strings.
 * @param dest Destination string (will be modified).
 * @param src Source string to append.
 * @return Pointer to the concatenated string.
 */
char *mathi_string_concat(char *dest, const char *src)
{
    int dlen = strlen(dest);
    for(int i = 0; src[i]; i++) dest[dlen + i] = src[i];
    dest[dlen + strlen(src)] = '\0';
    return dest;
}

/**
 * @brief Copy a string.
 * @param dest Destination string.
 * @param src Source string.
 * @return Pointer to the destination string.
 */
char *mathi_string_copy(char *dest, const char *src)
{
    int i = 0;
    while((dest[i] = src[i])) i++;
    return dest;
}

/**
 * @brief Compare two strings lexicographically.
 * @param a First string.
 * @param b Second string.
 * @return Negative, zero, or positive if a < b, a == b, or a > b.
 */
int mathi_string_compare(const char *a, const char *b)
{
    while(*a && (*a == *b)) { a++; b++; }
    return *(unsigned char*)a - *(unsigned char*)b;
}

/**
 * @brief Check if a string starts with a prefix.
 * @param str String to check.
 * @param prefix Prefix string.
 * @return 1 if str starts with prefix, 0 otherwise.
 */
int mathi_string_starts_with(const char *str, const char *prefix)
{
    while(*prefix) if(*prefix++ != *str++) return 0;
    return 1;
}

/**
 * @brief Check if a string ends with a suffix.
 * @param str String to check.
 * @param suffix Suffix string.
 * @return 1 if str ends with suffix, 0 otherwise.
 */
int mathi_string_ends_with(const char *str, const char *suffix)
{
    int slen = strlen(suffix), len = strlen(str);
    if(slen > len) return 0;
    return strcmp(str + len - slen, suffix) == 0;
}

/**
 * @brief Trim leading and trailing whitespace from a string.
 * @param str String to trim (modified in place).
 * @return Pointer to the trimmed string.
 */
char *mathi_string_trim(char *str)
{
    char *start = str;
    char *end;

    while(*start && isspace((unsigned char)*start)) start++;

    if(*start == 0) 
    {
        str[0] = '\0';
        return str;
    }

    end = start + strlen(start) - 1;
    while(end > start && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';

    if(start != str) memmove(str, start, strlen(start) + 1);

    return str;
}

/**
 * @brief Replace all occurrences of a character in a string.
 * @param str String to modify.
 * @param old Character to replace.
 * @param newc Replacement character.
 * @return Pointer to the modified string.
 */
char *mathi_string_replace(char *str, char old, char newc)
{
    for(int i = 0; str[i]; i++) if(str[i] == old) str[i] = newc;
    return str;
}