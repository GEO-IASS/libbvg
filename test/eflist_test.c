/**
 * @file eflist_test.c
 * Create an array consisting of 10000 natrual numbers in non-decreasing order.
 * Encode the array in Elias-Fano format and compare the eflist values with 
 * the original array.
 */

#include "eflist.h"
#include <stdlib.h>
#define N 10000
#define M 50

int test1() {
    int64_t *A = NULL;
    int64_t i = 0;
	elias_fano_list eflist;
    A = malloc(sizeof(int64_t) * N);
    srand(12345);
    A[0] = rand() % M;
    for (i = 1; i < N; i ++) {
        A[i] = A[i-1] + rand() % M;
    }
    
    eflist_create(&eflist, N, A[N-1]);
    eflist_addbatch(&eflist, A, N);
    // compare values
    for (i = 0; i < N; i ++) {
        if (A[i] != eflist_get(&eflist, i)) {
            printf("ERROR: eflist test failed!\n");
            return (-1);
        }
    }
    eflist_free(&eflist);
    free(A);
    return 0;
}


int test2() {
    int64_t *A = NULL;
    int64_t i = 0;
    elias_fano_list eflist;
	int64_t ai;
    srand(1234);
	ai = rand() % M;
    eflist_create(&eflist, N, M*N);
    
    eflist_add(&eflist, ai);
    for (i = 1; i < N; i ++) {
        ai = ai + rand() % M;
        eflist_add(&eflist, ai);
        if (ai != eflist_get(&eflist, i)) {
            printf("ERROR: eflist test failed!\n");
            return (-1);
        }
    }
    // compare values
    srand(1234);
    ai = rand() % M;
    for (i = 0; i < N; i ++) {
        if (ai != eflist_get(&eflist, i)) {
            printf("ERROR: eflist test failed!\n");
            return (-1);
        }
        ai = ai + rand() % M;
    }
    eflist_free(&eflist);
    free(A);
	return 0;
}

int main(int argc, char **argv)
{
    int rval = 0;
    printf("eflist test1 returns ");
    rval |= test1();
    printf("%i",rval);
    if (rval != 0) {
        printf("  FAILED");
    } else {
        printf("  passed");
    }
    printf("\n");
    
    printf("eflist test2 returns ");
    rval |= test2();
    printf("%i",rval);
    if (rval != 0) {
        printf("  FAILED");
    } else {
        printf("  passed");
    }
    printf("\n");
    
    return rval;
}
