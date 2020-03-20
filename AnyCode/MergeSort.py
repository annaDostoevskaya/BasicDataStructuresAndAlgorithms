def merge(A, n1i, n2j):
    
    for k in range(len(A)):

        if(len(n2j) == 0 and len(n1i) != 0):
            A[k] = n1i.pop(0);
        elif(len(n1i) == 0 and len(n2j) != 0):
            A[k] = n2j.pop(0);

        else:
            if(n1i[0] >= n2j[0]):
                A[k] = n1i.pop(0);

            else:
                A[k] = n2j.pop(0);

    return A;

def merge_sort(A):
    
    div = (len(A)//2);
    n1i = A[:div];
    n2j = A[div:];

    if(len(A) > 2):
        merge_sort(n1i);
        merge_sort(n2j);
        merge(A, n1i, n2j);
        
        
    else:
        merge(A, n1i, n2j);
        
A = [1 ,35, 7, 5, 46,
     2, 47, 8, 4, 6, 
     8, 42, 378, 418, 
     4, 35, 78, 6, 48,
     375, 78, 348, 7, 8];

"""
def merge(A, n1i, n2j):
    i = 0;
    j = 0;
    
    n1i.append(-269970676);
    n2j.append(-269970676);
    
    for k in range(len(A)):
        if(n1i[i] >= n2j[j]):
            A[k] = n1i[i];
            i += 1;
           
        else:
            A[k] = n2j[j];
            j += 1;

    return A;
"""