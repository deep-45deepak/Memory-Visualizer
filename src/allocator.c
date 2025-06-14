// Memory size: The memory size is defined as 1024 bytes.
#include "../include/allocator.h"
#include "../include/common.h"
#include <stdio.h>

// The memory array simulates the main memory, divided into blocks.
Block memory[MEMORY_SIZE];
// Used to assign unique process IDs.
int next_process_id = 1;

// Initializes all memory blocks to free state.
void initialize_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i].start = i;        // Start index of the block
        memory[i].size = 1;         // Each block is of size 1
        memory[i].allocated = false;// Block is free
        memory[i].process_id = -1;  // No process owns this block
        memory[i].is_page = false;  // Not part of a page by default
        memory[i].page_number = -1; // No page number
    }
}

// Finds the first fit for contiguous allocation.
int first_fit(int size) {
    int free_count = 0;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated) {
            free_count++;
            if (free_count == size) {
                return i - size + 1; // Found a suitable block
            }
        } else {
            free_count = 0;
        }
    }
    return -1; // No suitable block found
}

// Allocates memory for a process, either contiguous or paged.
int allocate_memory(int size, bool use_paging) {
    if (use_paging) {
        int pages_needed = (size + PAGE_SIZE - 1) / PAGE_SIZE;
        int allocated_pages = 0;
        for (int i = 0; i < MEMORY_SIZE && allocated_pages < pages_needed; i += PAGE_SIZE) {
            bool page_free = true;
            for (int j = 0; j < PAGE_SIZE; j++) {
                if (memory[i + j].allocated) {
                    page_free = false;
                    break;
                }
            }
            if (page_free) {
                for (int j = 0; j < PAGE_SIZE; j++) {
                    memory[i + j].allocated = true;
                    memory[i + j].process_id = next_process_id;
                    memory[i + j].is_page = true;
                    memory[i + j].page_number = allocated_pages;
                }
                allocated_pages++;
            }
        }
        if (allocated_pages == pages_needed) {
            return next_process_id++;
        } else {
            // Rollback allocation if not enough pages
            for (int i = 0; i < MEMORY_SIZE; i++) {
                if (memory[i].process_id == next_process_id) {
                    memory[i].allocated = false;
                    memory[i].process_id = -1;
                    memory[i].is_page = false;
                    memory[i].page_number = -1;
                }
            }
            return -1;
        }
    } else {
        int idx = first_fit(size);
        if (idx == -1) return -1;
        for (int i = idx; i < idx + size; i++) {
            memory[i].allocated = true;
            memory[i].process_id = next_process_id;
            memory[i].is_page = false;
            memory[i].page_number = -1;
        }
        return next_process_id++;
    }
}

// Frees all memory blocks belonging to a process.
void free_memory(int process_id) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i].process_id == process_id) {
            memory[i].allocated = false;
            memory[i].process_id = -1;
            memory[i].is_page = false;
            memory[i].page_number = -1;
        }
    }
}