#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct matrix {
    int mtrx[100][100];
    int rows;
    int columns;
} matrix_t;


typedef struct vector {
    int array[100];
    int length;
} vector_t;


matrix_t* matrix_multiply(matrix_t* A, matrix_t* B)
{
    assert(A->columns == B->rows);
    
    static matrix_t C;
    int j, i;
    C.rows = B->rows;
    C.columns = A->columns;
    matrix_t* ptr_C = &C;
    
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            C.mtrx[i][j] = 0;
        }
    }
    
    for(i = 0; i <= A->columns; i++) {
        for(j = 0; j <= B->columns; j++) {
            C.mtrx[i][j] += A->mtrx[i][j] * B->mtrx[i][j];
        }
    }
    
    return ptr_C;
}


matrix_t** matrix_chain_order(vector_t* p)
{
    int n = p->length;
    static matrix_t m, s;
    static matrix_t *ptr_m = &m, *ptr_s = &s;
    static matrix_t* array_ptr[] = {ptr_m, ptr_s};
    
    int i, l, k;
    int j, q;
    
    for(int i = 0; i <= n; i++) {
        m.mtrx[i][i] = 0;
        for(int l = 1; l <= n; l++) {
            j = i+l-1;
            m.mtrx[i][j] = 65437;
            for(int k = i; k <= j-1; k++) {
                q = m.mtrx[i][k] + m.mtrx[k+1][j] + p->array[i-1]*p->array[k]*p->array[j];
                if(q < m.mtrx[i][j]) {
                    m.mtrx[i][j] = q;
                    s.mtrx[i][j] = k;
                }
            }
        }
    }
    return array_ptr;
}


void print_oprimal_parents(matrix_t s, int i, int j)
{
    if(i == j) {
        printf("A");
    } else {
        printf("(");
        print_oprimal_parents(s, i, s.mtrx[i][j]);
        print_oprimal_parents(s, s.mtrx[i][j]+1, j);
        printf(")");
    }
}


int main()
{
    
    
    return 0;
}


/*
    matrix_t A;
    matrix_t B;
    A.rows = A.columns = 10;
    B.rows = B.columns = 10;
    
    
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            A.mtrx[i][j] = rand();
            B.mtrx[i][j] = rand();
        }
    }
    
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            printf("%5d ", A.mtrx[i][j]);
        }
        printf("\n");
    } printf("\n");
    
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            printf("%5d ", B.mtrx[i][j]);
        }
        printf("\n");
    } printf("\n");
    
    matrix_t* C = matrix_multiply(&A, &B);
    
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            printf("%9d ", C->mtrx[i][j]);
        }
        printf("\n");
    } printf("\n");
    
    return 0;
*/