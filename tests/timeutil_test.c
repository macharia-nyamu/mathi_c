/*
* Mathi C Library - timeutil_test.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mathi/timeutil.h"

void test_timeutil()
{
    printf("Starting time utility tests...\n\n");

    // Current timestamp
    long ts1 = mathi_current_timestamp();
    printf("Timestamp 1: %ld\n", ts1);

    printf("Sleeping for 1 second...\n");
    mathi_sleep_ms(1000);

    long ts2 = mathi_current_timestamp();
    printf("Timestamp 2: %ld\n", ts2);
    assert(ts2 - ts1 >= 1);
    printf("Timestamp difference verified: %ld seconds\n\n", ts2 - ts1);

    // Format time
    char buffer[32];
    mathi_format_time(buffer, sizeof(buffer));
    printf("Formatted current time: %s\n", buffer);
    assert(strlen(buffer) > 0);

    // Elapsed seconds
    int elapsed = mathi_elapsed_seconds(ts1, ts2);
    printf("Elapsed seconds between ts1 and ts2: %d\n", elapsed);
    assert(elapsed >= 1);
    printf("Elapsed time test passed!\n\n");

    printf("All timeutil tests passed!\n");
}

int main()
{
    test_timeutil();
    return 0;
}