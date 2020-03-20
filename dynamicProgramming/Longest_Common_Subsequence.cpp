#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <vector>

#define MAXIMUM_TABLE_SIZE 100

using namespace std;

typedef struct table {
    int array[MAXIMUM_TABLE_SIZE][MAXIMUM_TABLE_SIZE];
    int l1;
    int l2;
    int counter;
    int rows = 0;
    int columns = 0;
} table_t;


table_t* initTable(int l1, int l2)
{
    
    assert(l1 < MAXIMUM_TABLE_SIZE);
    assert(l2 < MAXIMUM_TABLE_SIZE);
    
    table_t *T = (table_t *)malloc(sizeof(table_t));
    
    T->l1 = l1;
    T->l2 = l2;
    T->counter = -2;
    
    for(int i = 0; i < T->l1; i++) {
        for(int j = 0; j < T->l2; j++)
            T->array[i][j] = 0;
    }
    
    return T;
}


void insertInTable(table_t *T, int value)
{
    assert(T->counter <= ((T->l1)*(T->l2)));
    
    T->array[T->rows][T->columns] = value;

    if( (T->columns) >= (T->l2) ) {
        T->columns = 0;
        T->rows++;
    } else {
        T->columns++;
    }
    
    if(T->rows >= T->l1)
        assert(false);
    
    printf("\n%d\n", T->counter);
    T->counter++;
}


void displayTable(table_t T)
{
    for(int i = 0; i < T.l1; i++) {
        for(int j = 0; j < T.l2; j++)
            printf("%d   ", T.array[i][j]);
        printf("\n");
    } printf("\n");
}


table_t** LCS_Length(vector<int> X, vector<int> Y)
{
    int m = X.size();
    int n = Y.size();
    
    table_t *b = initTable(m, n), *c = initTable(m, n);
    
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(X[i] == Y[j]) {
                c->array[i][j] = c->array[i-1][j-1] + 1;
                b->array[i][j] = 2; // 2 - "left-up"
            } else if(c->array[i-1][j] >= c->array[i][j-1]) {
                c->array[i][j] = c->array[i-1][j];
                b->array[i][j] = 3; // 3 - "up";
            } else {
                b->array[i][j] = 1; // 1 - "left";
            }
        }
    }
    static table_t *ret[] = {c, b};
    return ret;
}


void print_LCS(table_t b, vector<int> X, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    
    if(b.array[i][j] == 2) {
        print_LCS(b, X, i-1, j-1);
        printf("%d\n", X[i]);
    } else if(b.array[i][j] == 3) {
        print_LCS(b, X, i-1, j);
    } else {
        print_LCS(b, X, i, j-1);
    }
}


int main(int argc, char **argv)
{
    vector<int> X = {1, 3, 13, 3, 6, 1, 3};
    vector<int> Y = {3, 6, 13, 1, 3, 1};
    table_t** T = LCS_Length(X, Y);
    
    displayTable(*(T[0]));
    printf("\n");
    displayTable(*(T[1]));
    
    return 0;
}