#include "matrix.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h> /* for ENOSYS */

void print(matrix_t *m){
    for (int i = 0; i < (*m).rows; i++) {
        for (int j = 0; j < (*m).columns; j++) {
            printf( "%d ", (*m).content[i][j]);
        }
        printf( "\n");
} printf("\ndone!\n");
}

int matrix_allocate(matrix_t *m, int rows, int columns) {
    /* implement the function here ... */
    /* implement the function here ... */
    (*m).columns = columns;
    (*m).rows = rows;

    (*m).content = (int**)malloc(rows * sizeof(int *));
    if((*m).content == NULL) return -1;

    for(int i=0; i<rows; i++) {
    (*m).content[i] = (int*)malloc(columns * sizeof(int));
    if((*m).content[i] == NULL) return -1;
    }
    return 0;
    //return -ENOSYS;
     /* ENOSYS is a  standard error code that means 'function
                       not implemented'. We use it to force the failure of tests
                       while the functions are not written. Make sure to remove
                       it when you start to work on a function */
}

void matrix_free(matrix_t *m) {
    /* implement the function here ... */
    for(int i=0; i<(*m).rows; i++){
        free((*m).content[i]);
    }
    
    free((*m).content);
    
}

void matrix_init_n(matrix_t *m, int n) {
    /* implement the function here ... */
    for(int i = 0; i < (*m).rows; i++){
        for(int j = 0; j < (*m).columns; j++){
        (*m).content[i][j] = n;
        }
    }
    //  print(m);
}

void matrix_init_zeros(matrix_t *m) {
    /* implement the function here ... */
     matrix_init_n(m, 0);
    //  print(m);
}

int matrix_init_identity(matrix_t *m){
    /* implement the function here ... */
     int size = (*m).rows;
     if(size > (*m).columns){size = (*m).columns;}
        matrix_init_zeros(m);
        for (int i = 0; i < size; i++){
            (*m).content[i][i] = 1;
        }
        // print(m); 
        return 0;
    
    //return -ENOSYS;
}
void matrix_init_rand(matrix_t *m, int val_min, int val_max) {
    /* implement the function here ... */
     srand(time(NULL));
    int diff = 1 + val_max - val_min;
    for(int i = 0; i < (*m).rows; i++){
        for(int j = 0; j < (*m).columns; j++){
        (*m).content[i][j] = (rand()%diff) + val_min;
        }
    } 
    // print(m);
}

int matrix_equal(matrix_t *m1, matrix_t *m2) {
    /* implement the function here ... */
    if((m1 == m2)){return 1;}
    else if((*m1).rows == (*m2).rows && (*m1).columns == (*m2).columns){
        for(int i = 0; i < (*m1).rows; i++){
            for(int j = 0; j < (*m1).columns; j++){
                if((*m1).content[i][j] != (*m2).content[i][j]){
                    // print(m1);
                    // print(m2);
                    return 0;}
        }
    }
    // print(m1);
    //  print(m2);
     return 1;
    }
    return 0;
   
}

int matrix_sum(matrix_t *m1, matrix_t *m2, matrix_t *result) {
    /* implement the function here ... */
     if((*m1).rows == (*m2).rows && (*m1).columns == (*m2).columns &&
    matrix_allocate(result, (*m1).rows, (*m1).columns) == 0){
        for(int i = 0; i < (*m1).rows; i++){
        for(int j = 0; j < (*m1).columns; j++){
            (*result).content[i][j] = (*m1).content[i][j] + (*m2).content[i][j];
        } }
         return 0;}
   
    return -1;
    //return -ENOSYS;
}

int matrix_scalar_product(matrix_t *m, int scalar, matrix_t *result) {
    /* implement the function here ... */
    if(matrix_allocate(result, (*m).rows, (*m).columns) == 0){
        for(int i = 0; i < (*m).rows; i++){
        for(int j = 0; j < (*m).columns; j++){
            (*result).content[i][j] = (*m).content[i][j] * scalar;
        } }return 0;
    }
    return -1;
    //return -ENOSYS;
}

int matrix_transposition(matrix_t *m, matrix_t *result) {
    /* implement the function here ... */
    if(matrix_allocate(result, (*m).columns, (*m).rows) == 0){
        for(int i = 0; i < (*m).rows; i++){
            for(int j = 0; j < (*m).columns; j++){
                (*result).content[j][i] = (*m).content[i][j];
            }
        }
        // print(m);
        // print(result); 
        return 0;
    }
    return -1;
    // return -ENOSYS;
}

int matrix_product(matrix_t *m1, matrix_t *m2, matrix_t *result) {
    /* implement the function here ... */
    if((*m1).columns == (*m2).rows && matrix_allocate(result, (*m1).rows, (*m2).columns) == 0){
        for(int i = 0; i < (*m1).rows; i++){
        for(int j = 0; j < (*m2).columns; j++){
            for(int k = 0; k < (*m2).rows; k++)
            (*result).content[i][j] += (*m1).content[i][k] * (*m2).content[k][j];
        } } return 0;
    }
    return -1;
    // return -ENOSYS;
}

int matrix_dump_file(matrix_t *m, char *output_file) {
    /* implement the function here ... */
   FILE *file = fopen(output_file, "w");
    if (file != NULL) {
    for (int i = 0; i < (*m).rows; i++) {
        for (int j = 0; j < (*m).columns; j++) {
            fprintf(file, "%d ", (*m).content[i][j]);
        }
        fprintf(file, "\n");
    }
    }
    else {
       return -1;
    }
    fclose(file);
    return 0;
    //return -ENOSYS;
}

int matrix_allocate_and_init_file(matrix_t *m, char *input_file) {
    /* implement the function here ... */
    
    return -ENOSYS;
}