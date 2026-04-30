#include <stdio.h>
#include <time.h>

void log_event(const char *msg){
    FILE *f=fopen("logs/scan.log","a");
    if(!f) return;
    time_t t=time(NULL);
    fprintf(f,"[%s] %s\n",ctime(&t),msg);
    fclose(f);
}
