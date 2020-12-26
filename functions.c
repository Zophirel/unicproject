#include <stdio.h>
#include "citta.h"

int * getCouple(){
    int lower = 0, upper = SO_HEIGHT;
    int num[1];
    num[0] = (rand() % (upper - lower + 1)) + lower;
    upper = SO_WIDTH;
    num[1] = (rand() % (upper - lower + 1)) + lower;
    for(int i = 0; i < 2; i++){
        printf("%d", num[i]);
    }
    return num;
}

void createCity(){
    struct City city;
    int i, j; 
    for(i=0; i<SO_HEIGHT; i++) {
        for(j=0;j<SO_WIDTH;j++) {
            city.c_size[i][j] = "-";
        }
    }
    printf("Two Dimensional array elements:\n");
    for(i=0; i< SO_HEIGHT; i++) {
        for(j=0;j < SO_WIDTH;j++) {
            printf("%s ", city.c_size[i][j]);
            if(j == SO_WIDTH -1){
                printf("\n");
            }
        }
    }
    /*for(i = 0; i < SO_HOLES; i++){
        createHole(rand());
    }*/
    rand();
} 