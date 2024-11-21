#include <stdio.h>
#include <stdlib.h>

#include "memutil.h"

int main(void)
{
    void *ptr = NULL;

    if (memutil_alloc(&ptr, 10) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (memutil_dealloc(ptr) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
