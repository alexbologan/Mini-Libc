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
        errno = 12; // Set errno to indicate out of memory
        return NULL;
    }

    // Initialize the block with size information
    return (void*)(block + 4);
}

void *calloc(size_t nmemb, size_t size)
{
    // Allocate memory using malloc
	void* block = malloc(nmemb);

    // Check if 'malloc' returns NULL (an error indicator)
    if (block == MAP_FAILED) {
        return NULL;
    }

    // Initialize the block with size information
    memset(block, 0, nmemb);

    return block;
}

void free(void *ptr)
{
    // Cast the 'ptr' as a pointer to size_t
    size_t* ptr_new = (size_t*)(ptr);

    // Move the pointer back by 4 size_t elements to retrieve the size
    ptr_new -= 4;
    size_t size = ptr_new[0];

    // Call 'munmap' to deallocate the memory block and the header
    // Add 4 to the size to account for the memory allocated for the size
    munmap((void*)ptr_new, size + 4);
}

void *realloc(void *ptr, size_t size)
{
	// Use mmap to allocate memory
    void* block = malloc(size);

	// Verifing if the memory was allocated
    if (block == MAP_FAILED) {
        errno = 12; // Set errno to indicate out of memory
        return NULL;
    }

    // Free the existing memory pointed to by 'ptr'
    free(ptr);

    // Update the 'ptr' to point to the newly allocated memory block
    ptr = block;

    return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void* block = malloc(nmemb);

	// Verifing if the memory was allocated
    if (block == MAP_FAILED) {
        errno = 12; // Set errno to indicate out of memory
        return NULL;
    }

    // Free the existing memory pointed to by 'ptr'
    free(ptr);

    // Initialize the newly allocated memory block with zeros
    memset(block, size, nmemb);

    // Update the 'ptr' to point to the newly allocated memory block
    ptr = block;

    return ptr;
}
