#include <stdio.h>
#include <stdlib.h>
#include "coro.h"

extern char *dir;
extern void fs_walk();

void usage()
{
    puts("find -name file-name dir");
}

coro_t *coro_w;
coro_t *coro_f;

char *file_name;
void find() {
    
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        usage();
        return 0;
    }
    file_name = argv[2];
    dir = argv[3];
    puts(file_name);
    puts(dir);
    /* coro_w = coro_new(fs_walk);
    coro_f = coro_new(find);
    coro_boot(coro_f); */
    return 0;
}
