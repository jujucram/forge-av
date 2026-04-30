#ifndef HASH_H
#define HASH_H
void sha256_file(const char *path, char *output);
int hash_check(const char *hash);
#endif
