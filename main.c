#include <stdio.h>
#include <stdlib.h>
#include "core/scanner.h"
#include "core/process.h"
#include "core/monitor.h"
#include "core/thread_scan.h"

int main() {
    int choice;
    char path[256];

    while (1) {
        printf("\n=== ForgeAV ===\n");
        printf("1. Scan directory\n");
        printf("2. Scan processes\n");
        printf("3. Real-time monitor\n");
        printf("4. Fast scan (multi-thread)\n");
        printf("5. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // clean buffer
            continue;
        }

        switch(choice) {
            case 1:
                printf("Path: ");
                scanf("%255s", path);
                scan_directory(path);
                break;

            case 2:
                scan_processes();
                break;

            case 3:
                printf("Path: ");
                scanf("%255s", path);
                monitor_directory(path);
                break;

            case 4:
                printf("Path: ");
                scanf("%255s", path);
                start_thread_scan(path);
                break;

            case 5:
                printf("Au revoir!\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}