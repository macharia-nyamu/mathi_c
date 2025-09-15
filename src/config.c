/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/config.h"
#include <stdlib.h>
#include <string.h>

int config_load(const char *file_path) { return 0; }
const char* config_get_string(const char *key) { return ""; }
int config_get_int(const char *key, int *value) { if(value) *value=0; return 0; }
int config_set_string(const char *key, const char *value) { return 0; }
int config_save(const char *file_path) { return 0; }