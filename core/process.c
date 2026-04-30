#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <string.h>

void kill_process(DWORD pid){
    HANDLE h=OpenProcess(PROCESS_TERMINATE,0,pid);
    if(h){TerminateProcess(h,0);CloseHandle(h);}
}

void scan_processes(){
    PROCESSENTRY32 pe; HANDLE snap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    pe.dwSize=sizeof(pe);
    if(Process32First(snap,&pe)){
        do{
            printf("Process: %s\n",pe.szExeFile);
            if(strstr(pe.szExeFile,"virus")||strstr(pe.szExeFile,"malware"))
                kill_process(pe.th32ProcessID);
        }while(Process32Next(snap,&pe));
    }
    CloseHandle(snap);
}
