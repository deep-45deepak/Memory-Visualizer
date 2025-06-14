#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "common.h"

int allocate_memory(int size, bool use_paging);
void free_memory(int process_id);
int first_fit(int size);

#endif