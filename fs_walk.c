#define _GNU_SOURCE

#include "find.c"
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

/* #define PATH_MAX 256 */

char *dir;

void fs_walk() {
    struct stat info;
    stat(dir, &info);
    if (S_ISDIR(info.st_mode)) {
        DIR *directory = opendir(dir);
        struct dirent *entry;
        while (entry = readdir(directory)) {
            if (strcmp(entry->d_name, ".") == 0)
                continue;
            if (strcmp(entry->d_name, "..") == 0)
                continue;      
            char path[PATH_MAX];
            memset(path, 0, sizeof(path));
            memcpy(path, dir, strlen(dir));
            path[strlen(path)] = '/';
            int n = strlen(path);
            memcpy(path + n, entry->d_name, strlen(entry->d_name));

            if (entry->d_type == DT_DIR) {
                char *tmp = dir;
                dir = path;
                fs_walk();
                dir = tmp;
            }
            else if (entry->d_type == DT_REG)
                coro_yield((unsigned long)path);
            
            memset(path, 0, sizeof(path));
        }
        closedir(directory);
    }
    else {
        coro_yield(dir);
    }
}
