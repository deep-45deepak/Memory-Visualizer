#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define color codes for terminal output
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define MEMORY_SIZE 64
#define PAGE_SIZE 8

typedef struct {
    int start;
    int size;
    bool allocated;
    int process_id;
    bool is_page;
    int page_number;
} Block;

extern Block memory[MEMORY_SIZE];
extern int next_process_id;

void initialize_memory();
void clear_screen();

#endif