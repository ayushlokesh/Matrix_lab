#include "matrix.h"
#include <stdio.h>

int main(){

matrix_t m, temp, result;
    char *file = "matrix-samples/valid.txt";

    ( matrix_allocate_and_init_file(&m, file));
    // for(int i=0; i<m.rows; i++)
    //     for(int j=0; j<m.columns; j++)
    //         printf("%d", m.content[i][j]);
    matrix_free(&m);
}