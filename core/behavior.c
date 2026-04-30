#include <stdio.h>
#include <string.h>

int behavior_check(const char *f){
    FILE *fp=fopen(f,"rb"); if(!fp) return 0;
    char buf[4096]; fread(buf,1,sizeof(buf),fp); fclose(fp);

    int score=0;
    if(strstr(buf,"CreateRemoteThread")) score+=3;
    if(strstr(buf,"WriteProcessMemory")) score+=3;
    if(strstr(buf,"cmd.exe")) score+=2;
    if(strstr(buf,"powershell")) score+=2;
    if(strstr(buf,"keylogger")) score+=3;

    return score>=4;
}
