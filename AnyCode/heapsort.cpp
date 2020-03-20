#include <stdio.h>
#include <vector>


typedef struct vocabulary {
    
    int value;
    int key = -645120;
    
} vocabulary_t;


typedef struct heap {
    std::vector<vocabulary_t> array;
    int heap_size;
    int lenght;
} heap_t;


int parent(int i)
{
    return i/2;
}


int left(int i)
{
    return 2*i;
}


int right(int i)
{
    return 2*i+1;
}


void swap(int* a, int* b)
{
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
}


// max_heapify: maintain max-heap property;
void max_heapify(heap_t* A, int i)
{
    int l = left(i);
    int r = right(i);
    int largest;

    if(l <= A->heap_size && A->array[l].value > A->array[i].value) {
        largest = l;
    } else {
        largest = i;
    }
    
    if(r <= A->heap_size && A->array[r].value > A->array[largest].value) {
        largest = r;
    }
    
    if(largest != i) {
        swap(&(A->array[i].value), &(A->array[largest].value));
        max_heapify(A, largest);
    }
}


// min_heapify: maintain min-heap property;
void min_heapify(heap_t* A, int i)
{
    int l = left(i);
    int r = right(i);
    int less = 0;
    
    if(l <= A->heap_size && A->array[l].value < A->array[i].value) {
        less = l;
    } else {
        less = i;
    }
    
    if(r <= A->heap_size && A->array[r].value < A->array[less].value) {
        less = r;
    }
    
    if(less != i) {
        swap(&(A->array[i].value), &(A->array[less].value));
        min_heapify(A, less);
    }

}


// build_heap: creat max(min)-heap for array;
void build_heap(heap_t* A)
{   
    A->heap_size = A->lenght;
    for(int i = A->lenght/2; i >= 0; i--) {
        // if want min-heap remake function;
        max_heapify(A, i);
    }
}


// heap_sort: sort array without more memory;
void heap_sort(heap_t* A)
{
    build_heap(A);
    
    for(int i = A->lenght; i >= 1; i--) {
        swap(&(A->array[0].value), &(A->array[i].value));
        A->heap_size--;
        max_heapify(A, 0);
    }
}

/*
int main(int argc, char** argv)
{
    heap_t A;
    A.array = {66, 456, 7, 768, 64, 7, 2, 48, 12, 74};
    A.heap_size = 4;
    A.lenght = 9;
    
    for(int i = 0; i <= A.lenght; i++) {
        printf("%d ", A.array[i]);
    } printf("\n");
    
    heap_sort(&A);

    for(int i = 0; i <= A.lenght; i++) {
        printf("%d ", A.array[i]);
    } printf("\n");

    return 0;
}
*/