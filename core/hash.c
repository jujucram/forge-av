#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
#include <string.h>
#pragma comment(lib, "advapi32.lib")

void sha256_file(const char *path, char *output) {
    HCRYPTPROV hProv; HCRYPTHASH hHash;
    BYTE buffer[1024]; DWORD read;

    FILE *file = fopen(path,"rb");
    if (!file) return;

    CryptAcquireContext(&hProv,NULL,NULL,PROV_RSA_AES,CRYPT_VERIFYCONTEXT);
    CryptCreateHash(hProv,CALG_SHA_256,0,0,&hHash);

    while ((read=fread(buffer,1,sizeof(buffer),file)))
        CryptHashData(hHash,buffer,read,0);

    BYTE hash[32]; DWORD len=32;
    CryptGetHashParam(hHash,HP_HASHVAL,hash,&len,0);

    for(int i=0;i<32;i++)
        sprintf(output+i*2,"%02x",hash[i]);

    fclose(file);
}

int hash_check(const char *hash) {
    FILE *f=fopen("database/hashes.txt","r");
    if(!f) return 0;
    char line[128];
    while(fgets(line,sizeof(line),f)){
        line[strcspn(line,"\n")]=0;
        if(!strcmp(hash,line)) return 1;
    }
    fclose(f);
    return 0;
}
