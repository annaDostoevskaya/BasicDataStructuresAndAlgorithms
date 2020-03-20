#include <stdio.h>
#include <cstddef>


typedef struct linked_list {
    
    int key;
    struct linked_list* next = NULL;
    struct linked_list* prev = NULL;
    struct linked_list* head = NULL;

} list_t;



list_t list_search(list_t L, int k)
{
    list_t x = *(L.head);

    while(x != NULL && x.key != k) {
        x = *(x.next);
    }
    
    return x;
}


void list_insert(list_t* L, list_t* x)
{
    x->next = L->head;
    if(L->head != NULL) {
        *(L->head->prev) = *(x);
    }
    
    *(L->head) = *(x);
    x->prev = NULL;
}


void list_delete(list_t* L, list_t* x)
{
    if(x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        L->head = x->next;
    }
    
    if(x->next != NULL) {
        x->next->prev = x->prev;
    }
}


int main()
{
    
    return 0;
}