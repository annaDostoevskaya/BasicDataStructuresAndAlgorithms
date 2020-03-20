typedef struct equeue {
    
    int array[100];
    int head;
    int tail;
    
    int length;
    
} equeue_t;


void enqueue(equeue_t* Q, int x)
{
    Q->array[Q->tail] = x;
    if(Q->tail == Q->length) {
        Q->tail = 1;
    } else {
        Q->tail += 1;
    }
}


int dequeue(equeue_t* Q)
{
    int x = Q->array[Q->head];
    if(Q->head == Q->length) {
        Q->head = 1;
    } else {
        Q->head += 1;
    }
    return x;
}