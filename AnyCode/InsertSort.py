def InsertSort(A):
    
    for j in range(1, len(A)):
        key = A[j];
        
        i = j - 1;
        while(i > -1 and A[i] > key):
            A[i+1] = A[i];
            i -= 1;

        A[i+1] = key;

    return A;
    
    
sortm = InsertSort([5, 2, 4, 6, 1, 3]);
print(sortm);