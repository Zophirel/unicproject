#include <stdio.h>
#include "citta.h"

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
}