#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "citta.h"

#ifdef DENSE
    const int SO_SOURCES = SO_WIDTH * SO_HEIGHT - SO_HOLES;
    int SO_TAXI = SO_SOURCES / 2;
#endif

int main(int argc, char * argv[]){
    createCity();
    return 0;
}
