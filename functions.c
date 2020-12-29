#include <stdio.h>
#include "citta.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
void getCouple(int *num){
    int lower = 0, upper;
    for(int i = 0; i < 2; i++){
        if(i == 1){
            upper = SO_WIDTH;
            srand ( time(NULL) );
            num[i] = (rand() % (upper - lower + 1)) + lower;
        }
        else{
            upper = SO_HEIGHT;
            srand ( time(NULL) );
            num[i] = (rand() % (upper - lower + 1)) + lower;
        }
    }
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
    
    int num[2] = {0, 0};
    getCouple(num);
    for(i = 0; i < 2; i++){
        printf("%d \n",num[i]);
    }

} 