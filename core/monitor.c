#include <windows.h>
#include <stdio.h>

void monitor_directory(const char *path){
    HANDLE h=CreateFile(path,FILE_LIST_DIRECTORY,
    FILE_SHARE_READ|FILE_SHARE_WRITE|FILE_SHARE_DELETE,
    NULL,OPEN_EXISTING,FILE_FLAG_BACKUP_SEMANTICS,NULL);

    if(h==INVALID_HANDLE_VALUE) return;

    char buf[1024]; DWORD bytes;
    printf("[Monitoring %s]\n",path);

    while(1){
        if(ReadDirectoryChangesW(h,buf,sizeof(buf),TRUE,
        FILE_NOTIFY_CHANGE_FILE_NAME,&bytes,NULL,NULL)){
            printf("[CHANGE DETECTED]\n");
        }
    }
}
