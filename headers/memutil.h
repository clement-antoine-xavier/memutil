#pragma once

#include <stddef.h>

typedef struct memutil_metadata_s {
    int page_size;
    void *break_addr;
} memutil_metadata_t;

int memutil_alloc(void **ptr, size_t size);

int memutil_dealloc(void *ptr);
