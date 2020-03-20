#include <stdio.h>

void InsertSort(int *m1, int size)
{
    int j, i, key;
    
    for(j = 1; j <= (size-1); j++){
        key = m1[j];
        
        i = j - 1;
        while(i > -1 && m1[i] > key){
            m1[i+1] = m1[i];
            i -= 1;
        }
        m1[i+1] = key;
    }
}

int main()
{
    int a[] = {5, 2, 4, 6, 1, 3};
    InsertSort(a, 6);
    
    for(int i = 0; i <= 5; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}