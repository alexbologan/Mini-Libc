// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    // Use mmap to allocate memory
    size_t* block = (size_t*)mmap(NULL, size + 4, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    block[0] = size;
	// Verifing if the memory was allocated
    if (block == MAP_FAILED) {
        errno = ENOMEM;
        return NULL;
    }

    // Initialize the block with size information
    return (void*)(block + 4);
}

void *calloc(size_t nmemb, size_t size)
{
	void* block = malloc(nmemb);

    if (block == MAP_FAILED) {
        return NULL;
    }
    // Initialize the block with size information
    memset(block, 0, nmemb);

    return block;
}

void free(void *ptr)
{
    size_t* ptr_new = (size_t*)(ptr);
    ptr_new -= 4;
    size_t size = ptr_new[0];

    munmap((void*)ptr_new, size + 4);
}

void *realloc(void *ptr, size_t size)
{
	// Use mmap to allocate memory
    void* block = malloc(size);

	// Verifing if the memory was allocated
    if (block == MAP_FAILED) {
        errno = ENOMEM;
        return NULL;
    }
    free(ptr);
    ptr = block;
    // Initialize the block with size information

    return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void* block = malloc(nmemb);

	// Verifing if the memory was allocated
    if (block == MAP_FAILED) {
        errno = ENOMEM;
        return NULL;
    }
    free(ptr);
    memset(block, 0, size);
    ptr = block;
    // Initialize the block with size information

    return ptr;
}
