#include <vector>
#include <stdlib.h>
#include <stdio.h>

typedef struct list {
    
    std::vector<int> array;
    int length;
    
} list_t;


void swap(int* a, int* b)
{
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
}


// partition: change the order of element of array;
int partition(list_t* A, int p, int r)
{
    int x = A->array[r];
    int i = p - 1;
    
    for(int j = p; j <= r-1; j++) {
        if(A->array[j] <= x) {
            i++;
            swap(&(A->array[i]), &(A->array[j]));
        }
    }
    
    swap(&(A->array[i+1]), &(A->array[r]));
    return i+1;
}


// quick_sort: algorith quick sort;
void quick_sort(list_t* A, int p, int r)
{

    if(p < r) {
        int q = randomized_partiotion(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    } 

}


// inarray: return true if value in array;
int inarray(int *array, int length, int value)
{
    int i;
    
    for(i = 0; i <= length; i++) {
        if(array[i] == value) {
            return true;
        }
    }
    
    return false;
}


// randomized_partiotion: randomized reference element;
int randomized_partiotion(list_t* A, int p, int r)
{
    int i = random(); // TODO random();
    
    swap(&(A->array[p]), &(A->array[r]));
    
    int prttn = partition(A, p, r);
    
    return prttn;
}


int main(int argc, char** argv)
{
    return 0;
}