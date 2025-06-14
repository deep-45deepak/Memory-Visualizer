
#include "../include/fragmentation.h"
#include "../include/common.h"
#include <stdio.h>

void calculate_fragmentation() {
    int free_blocks = 0, largest_free = 0, current_free = 0;
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (!memory[i].allocated) {
            free_blocks++;
            current_free++;
            if (current_free > largest_free)
                largest_free = current_free;
        } else {
            current_free = 0;
        }
    }
    printf("\nFragmentation Report:\n");
    printf("Total free blocks: %d\n", free_blocks);
    printf("Largest contiguous free block: %d\n", largest_free);
}