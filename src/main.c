#include "../include/common.h"
#include "../include/visualizer.h"
#include "../include/allocator.h"
#include "../include/fragmentation.h"
#include <stdio.h>

void print_welcome() {
    clear_screen();
    print_header("Memory Allocation Visualizer");
    printf("Welcome to the Memory Allocation Visualizer!\n");
}

void run_demo() {
    initialize_memory();
    print_header("Demo: Contiguous Allocation");
    int pid1 = allocate_memory(10, false);
    int pid2 = allocate_memory(8, false);
    visualize_memory();
    visualize_memory_details();
    printf("\nFreeing process %d...\n", pid1);
    free_memory(pid1);
    visualize_memory();
    calculate_fragmentation();
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void interactive_mode() {
    initialize_memory();
    int running = 1;
    while (running) {
        print_header("Interactive Mode");
        visualize_memory();
        printf("\nOptions:\n");
        printf("1. Allocate memory (contiguous)\n");
        printf("2. Allocate memory (paging)\n");
        printf("3. Free memory\n");
        printf("4. Show fragmentation\n");
        printf("5. Show details\n");
        printf("6. Exit to main menu\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            int size;
            printf("Enter size to allocate: ");
            scanf("%d", &size);
            int pid = allocate_memory(size, choice == 2);
            if (pid == -1)
                printf(COLOR_RED "Allocation failed!\n" COLOR_RESET);
            else
                printf(COLOR_GREEN "Allocated to process %d\n" COLOR_RESET, pid);
        } else if (choice == 3) {
            int pid;
            printf("Enter process id to free: ");
            scanf("%d", &pid);
            free_memory(pid);
            printf("Freed memory for process %d\n", pid);
        } else if (choice == 4) {
            calculate_fragmentation();
        } else if (choice == 5) {
            visualize_memory_details();
        } else if (choice == 6) {
            running = 0;
        } else {
            printf(COLOR_RED "Invalid choice\n" COLOR_RESET);
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    while (1) {
        print_welcome();
        printf("\n" COLOR_CYAN "Main Menu:\n" COLOR_RESET);
        printf("1. Run demonstration\n");
        printf("2. Interactive mode\n");
        printf("3. Exit\n");
        printf("\nEnter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                run_demo();
                break;
            case 2:
                interactive_mode();
                break;
            case 3:
                return 0;
            default:
                printf(COLOR_RED "Invalid choice\n" COLOR_RESET);
                printf("\nPress Enter to continue...");
                getchar();
                getchar();
        }
    }
}