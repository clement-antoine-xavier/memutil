#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "memutil.h"

static void init_metadata(memutil_metadata_t *metadata)
{
    metadata->page_size = getpagesize();
    printf("Page size: %d\n", metadata->page_size);

    metadata->break_addr = sbrk(0);
    printf("Break address: %p\n", metadata->break_addr);
}

int memutil_alloc(void **ptr, size_t size)
{
    static memutil_metadata_t metadata = {0};

    if (memcmp(&metadata, &(memutil_metadata_t){0}, sizeof(metadata)) == 0)
        init_metadata(&metadata);
    
    printf("Allocating %zu bytes\n", size);

    *ptr = NULL;

    return EXIT_SUCCESS;
}

int memutil_dealloc(void *ptr)
{
    printf("Deallocating %p\n", ptr);

    return EXIT_SUCCESS;
}
