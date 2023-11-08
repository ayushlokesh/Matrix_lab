# include <stdio.h>
# include "matrix.h"

int main(){
 matrix_t m1, m2, result, expected;
    char *f1 = "matrix-samples/m-5-10-a.txt";
    char *f2 = "matrix-samples/m-10-5-a.txt";
    char *f3 = "matrix-samples/matrix-product.txt";
    printf("here m1 is loaded....");
    ( matrix_allocate_and_init_file(&m1, f1));
    printf("here m2 is loaded....");
    ( matrix_allocate_and_init_file(&m2, f2));
    printf("here expected is loaded....");
    ( matrix_allocate_and_init_file(&expected, f3));

    ( matrix_product(&m1, &m2, &result));

    (matrix_equal(&expected, &result));
    
    matrix_free(&m1);
    matrix_free(&m2);
    matrix_free(&expected);
    matrix_free(&result);
}