#include <assert.h>
#include <vector>
#include "heapsort.cpp"


int heap_maximum(heap_t A)
{
    return A.array[0].value;
}


// heap_extract_max: remove and return element of 'S' with largest key;
int heap_extract_max(heap_t* A)
{
    assert(A->heap_size < 0);
    
    int max = A->array[0].value;
    A->array[0] = A->array[A->heap_size];
    A->heap_size--;
    max_heapify(A, 0);
    return max;
}


// heap_increase_key: increase key of 'x' (key > x.key);
void heap_increase_key(heap_t* A, int i, int key)
{
    assert(key < A->array[i].key);
    
    A->array[i].key = key;
    while(i > 0 && A->array[parent(i)].value < A->array[i].value) {
        
        swap(&(A->array[parent(i)].value), &(A->array[i].value));
        swap(&(A->array[parent(i)].key), &(A->array[i].key));
        
        i = parent(i);
    }
    
}


// max_heap_insert: insert new element in heap;
void max_heap_insert(heap_t* A, int key)
{
    A->heap_size++;
    A->array[A->heap_size].value = -645120;
    heap_increase_key(A, A->heap_size, key);
}


int main(int argc, char** argv)
{
    
    return 0;
}