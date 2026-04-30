#include <stdio.h>
#include <time.h>

void quarantine_file(const char *f){
    char newp[512];
    sprintf(newp,"quarantine/%ld_file",time(NULL));
    rename(f,newp);
}
