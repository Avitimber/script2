#include <stdio.h>
#include <stdlib.h>
#include "coro.h"

#define N 8

coro_t *coro_p;
coro_t *coro_f;
coro_t *coro_c;

void produce() {
    puts("PRODUCE");
    for (int i = 0; i < N; i ++) {
        int x = i;
        printf("produce %d\n", x);
        coro_yield(x);
    }
}

void filter() {
    puts("\tFILTER");
    for (int i = 0; i < N; i ++) {
        int x = coro_resume(coro_p);
        printf("\tfilter %d -> %d\n", x, 10 * x);
        coro_yield(10 * x);
    }
}

void consume() {
    puts("\t\tCONSUME");
    for (int i = 0; i < N; i ++) {
        int x = coro_resume(coro_f);
        printf("\t\tconsume %d\n", x);
    }
    puts("\t\tEND");
    exit(0);
}

int main()
{
    coro_p = coro_new(produce);
    coro_f = coro_new(filter);
    coro_c = coro_new(consume);
    coro_boot(coro_c);
    return 0;
}
