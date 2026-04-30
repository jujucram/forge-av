#include <stdio.h>
#include <string.h>

int heuristic_check(const char *f){
    if(strstr(f,".exe")||strstr(f,".bat")||strstr(f,".vbs")||strstr(f,".ps1"))
        return 1;
    FILE *fp=fopen(f,"rb"); if(!fp) return 0;
    fseek(fp,0,SEEK_END); long s=ftell(fp); fclose(fp);
    return (s<1024||s>100000000);
}

int signature_check(const char *f){
    FILE *file=fopen(f,"rb");
    FILE *db=fopen("database/signatures.txt","r");
    if(!file||!db) return 0;

    char buf[2048]; fread(buf,1,sizeof(buf),file);
    char sig[256];

    while(fgets(sig,sizeof(sig),db)){
        sig[strcspn(sig,"\n")]=0;
        if(strstr(buf,sig)) return 1;
    }
    fclose(file); fclose(db);
    return 0;
}
