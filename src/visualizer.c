#include "../include/visualizer.h"
#include "../include/common.h"
#include <stdio.h>

void print_header(const char* title) {
    printf("\n" COLOR_CYAN "=== %s ===\n" COLOR_RESET, title);
}

void visualize_memory() {
    printf("\nMemory Visualization (Each block = 1 unit, Total: %d blocks):\n", MEMORY_SIZE);

    // Print block indices for reference
    printf("Index: ");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0)
            printf("%-2d", i / 10 * 10); // Print every 10th index
        else
            printf("  ");
    }
    printf("\n       ");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%d", i % 10);
    }
    printf("\n");

    // Print memory blocks
    printf("Blocks:");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i].allocated) {
            if (memory[i].is_page)
                printf(COLOR_YELLOW "|P"); // Page
            else
                printf(COLOR_GREEN "|%d", memory[i].process_id); // Process ID
        } else {
            printf(COLOR_RED "|_");
        }
    }
    printf(COLOR_RESET "|\n");

    // Print legend
    printf("\nLegend: " COLOR_GREEN "|<PID>" COLOR_RESET " = Process, " COLOR_YELLOW "|P" COLOR_RESET " = Page, " COLOR_RED "|_" COLOR_RESET " = Free\n");
    printf("Block size: 1 unit each. Total blocks: %d. Page size: %d blocks.\n", MEMORY_SIZE, PAGE_SIZE);
}

void visualize_memory_details() {
    printf("\nDetailed Memory Blocks (Block size: 1 unit):\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("Block %3d: ", i);
        if (memory[i].allocated) {
            printf(COLOR_GREEN "Allocated (PID %d)", memory[i].process_id);
            if (memory[i].is_page)
                printf(", Page %d", memory[i].page_number);
        } else {
            printf(COLOR_RED "Free");
        }
        printf(COLOR_RESET "\n");
    }
}