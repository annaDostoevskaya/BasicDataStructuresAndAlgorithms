typedef struct table {
    
    int table[100];
    int length;
    
} table_t;


void copy_array(int *A, int i, int j
                int *B, int k, int l) {

    for(i, k; i <= j, k <= l; i++, k++)
        A[i] = B[k];
    
}


int **lcs_length(table_t X, table_t Y)
{
    int m = X.length;
    int n = Y.length;
    
    table_t b, c;
    
    for(int i = 0; i <= m; i++) 
        c[i] = 0;
    for(int j = 0; j <= n; j++)
        c[j] = 0;
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(X[i] == Y[j]) {
                copy_array(C, i, j, C, i-1, j-1)
            }
        }
    }
}