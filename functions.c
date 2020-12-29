#include <stdio.h>
#include "citta.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define LEN(arr) (sizeof(arr) / sizeof(*arr))

typedef struct{
    char * c_size[SO_HEIGHT][SO_WIDTH];
} City;

void genCouples(int *r, int *c){
    int lower = 0, upper = SO_HEIGHT-1, i = 0;
    srand ( time(0) );
    for(i = 0; i < SO_HOLES; i++){ 
        r[i] = (rand() % (upper - lower + 1)) + lower;
    }

    upper = SO_WIDTH-1;
    for(i = 0; i < SO_HOLES; i++){
        c[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

void editCouples(int i, int * r, int * c){
    int lower = 0, upper = SO_HEIGHT-1;
    r[i] = (rand() % (upper - lower + 1)) + lower;
    upper = SO_WIDTH-1;
    c[i] = (rand() % (upper - lower + 1)) + lower;
}


City check(int i, int * r, int * c, City z){
    //Angolo alto a sx
    if(r[i] == 0 && c[i] == 0 && z.c_size[r[i]][c[i]] != "H"){    
        if(z.c_size[r[i+1]][c[i]] != "H" && z.c_size[r[i+1]][c[i+1]] != "H" && z.c_size[r[i]][c[i+1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Angolo basso a sx
    else if(r[i] == SO_HEIGHT-1 && c[i] == 0 && z.c_size[r[i]][c[i]] != "H"){ 
        if(z.c_size[r[i-1]][c[i]] != "H" && z.c_size[r[i-1]][c[i+1]] != "H" && z.c_size[r[i]][c[i+1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Angolo alto a dx
    else if(r[i] == 0 && c[i] == SO_WIDTH-1 && z.c_size[r[i]][c[i]] != "H"){
        if(z.c_size[r[i+1]][c[i]] != "H" && z.c_size[r[i+1]][c[i-1]] != "H" && z.c_size[r[i]][c[i-1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Angolo basso a dx
    else if(r[i] == SO_HEIGHT -1 && c[i] == SO_WIDTH-1 && z.c_size[r[i]][c[i]] != "H"){
        if(z.c_size[r[i-1]][c[i]] != "H" && z.c_size[r[i+1]][c[i-1]] != "H" && z.c_size[r[i]][c[i-1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Bordo alto
    else if(r[i] == 0 && z.c_size[r[i]][c[i]] != "H"){    
        if(z.c_size[r[i]][c[i-1]] != "H" && z.c_size[r[i]][c[i+1]] != "H" && z.c_size[r[i+1]][c[i-1]] != "H" && z.c_size[r[i+1]][c[i]] != "H" && z.c_size[r[i+1]][c[i+1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Bordo basso
    else if(r[i] == SO_HEIGHT -1 && z.c_size[r[i]][c[i]] != "H"){         
        if(z.c_size[r[i]][c[i-1]] != "H" && z.c_size[r[i]][c[i+1]] != "H" && z.c_size[r[i-1]][c[i-1]] != "H" && z.c_size[r[i-1]][c[i]] != "H" && z.c_size[r[i-1]][c[i+1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Bordo sinistro
    else if(c[i] == 0 && z.c_size[r[i]][c[i]] != "H"){
        if(z.c_size[r[i-1]][c[i]] != "H" && z.c_size[r[i+1]][c[i]] != "H" && z.c_size[r[i-1]][c[i+1]] != "H" && z.c_size[r[i]][c[i+1]] != "H" && z.c_size[r[i+1]][c[i+1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //Bordo destro
    else if(c[i] == SO_WIDTH -1 && z.c_size[r[i]][c[i]] != "H"){
        if(z.c_size[r[i-1]][c[i]] != "H" && z.c_size[r[i+1]][c[i]] != "H" && z.c_size[r[i+1]][c[i-1]] != "H" && z.c_size[r[i]][c[i-1]] != "H" && z.c_size[r[i-1]][c[i-1]] != "H"){
                z.c_size[r[i]][c[i]] = "H";
        }else{
            editCouples(i, r, c);
            check(i,r,c,z);
        }
    }
    //centrale  
    else if(z.c_size[r[i]][c[i]] != "H"             //guardo nella posizione indicata da r e c
                && z.c_size[r[i+1]][c[i]] != "H"    //guardo in basso
                && z.c_size[r[i-1]][c[i]] != "H"    //guardo in alto
                && z.c_size[r[i]][c[i+1]] != "H"    //guardo a destra
                && z.c_size[r[i]][c[i-1]] != "H"    //guardo a sinistra
                && z.c_size[r[i+1]][c[i-1]] != "H"  //guardo in basso a sinistra
                && z.c_size[r[i+1]][c[i+1]] != "H"  //guardo in basso a destra
                && z.c_size[r[i-1]][c[i-1]] != "H"  //guardo in alto a sinistra
                && z.c_size[r[i-1]][c[i+1]] != "H") //guardo in alto a destra
            {
                z.c_size[r[i]][c[i]] = "H"; 
            }
        else{
            editCouples(i, r, c);
            check(i,r,c,z);
    }
    return z;
}


void createCity(){
    City fc;
    int i = 0, j = 0; 
    
    for(i=0; i < SO_HEIGHT; i++) {
        for(j=0;j < SO_WIDTH;j++) {
            fc.c_size[i][j] = "-";
        }
    }
    
    int r[SO_HOLES] = {0};
    int c[SO_HOLES] = {0};
    genCouples(r, c);
    
    for(i = 0; i < LEN(r); i++){
        printf("%d(R:%d C:%d), ", i, r[i], c[i]);
    }
    


    for(i=0; i < SO_HOLES; i++){
        fc = check(i,r,c,fc);
    }
    
    printf("\n");
    for(i = 0; i < LEN(r); i++){
        printf("%d(R:%d C:%d), ", i, r[i], c[i]);
    }


    printf("Citta': \n");
    for(i=0; i< SO_HEIGHT; i++) {
        for(j=0;j < SO_WIDTH;j++) {
            printf("%s ", fc.c_size[i][j]);
            if(j == SO_WIDTH -1){
                printf("\n");
            }
        }
    }
    
    
    /*for(i=0; i< SO_HEIGHT; i++) {
        for(j=0;j < SO_WIDTH;j++) {
            printf("%s ", z.c_size[i][j]);
            if(j == SO_WIDTH -1){
                printf("\n");
            }
        }
    }*/
} 