#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "scanner.h"
#include "hash.h"
#include "heuristic.h"
#include "behavior.h"
#include "../security/quarantine.h"
#include "../security/logger.h"

void scan_file(const char *filepath) {
    char hash[65] = {0};

    sha256_file(filepath, hash);

    int score = heuristic_check(filepath)
            + signature_check(filepath)
            + hash_check(hash)
            + behavior_check(filepath);

    if (score >= 2) {
        printf("[!!!] THREAT: %s\n", filepath);
        quarantine_file(filepath);
        log_event("Threat detected");
    } else {
        printf("[OK] %s\n", filepath);
    }
}

void scan_directory(const char *path) {
    char search_path[512];
    WIN32_FIND_DATA fd;
    HANDLE hFind;

    sprintf(search_path, "%s\\*", path);

    hFind = FindFirstFile(search_path, &fd);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Cannot open directory\n");
        return;
    }

    do {
        if (strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0)
            continue;

        char fullpath[512];
        sprintf(fullpath, "%s\\%s", path, fd.cFileName);

        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            scan_directory(fullpath);
        } else {
            scan_file(fullpath);
        }

    } while (FindNextFile(hFind, &fd));

    FindClose(hFind);
}