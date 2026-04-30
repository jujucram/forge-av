#include <windows.h>
#include "scanner.h"

DWORD WINAPI thread_scan(LPVOID p){
    scan_directory((char*)p);
    return 0;
}

void start_thread_scan(const char *p){
    CreateThread(NULL,0,thread_scan,(LPVOID)p,0,NULL);
}
