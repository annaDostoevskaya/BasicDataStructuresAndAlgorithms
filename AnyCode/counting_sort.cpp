#include <vector>


typedef struct list {
    
    std::vector<int> array;
    int length;
    
} list_t;


void counting_sort(list* A, list* B, int k)
{
    static list_t C;
    C.array[k];

    int i;
    int j;
 
    for(i = 0; i <= k; i++) {
        C.array[i] = 0;
    }
    
    for(j = 0; j <= k; j++) {
        C.array[A->array[j]] += 1;
    }
    
    for(i = 0; i <= k; i++) {
        C.array[i] += 1;
    }
    
    for(j = A->length; j >= 0; j--) {
        B->array[ C.array[ A->array[j] ] ] = A->array[j];
        C.array[ A->array[j]] -= 1;
    }
}