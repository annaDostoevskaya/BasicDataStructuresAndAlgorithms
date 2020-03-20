def smaller(array):
    small = array[0]
    
    for i in range(0, len(array)-1):
        if(small > array[i+1]):
            small = array[i+1];
    
    return small;

def select_sort(array):
    copy2 = [];
    copy1 = array[:];
    for i in range(0, len(array)):
        s = smaller(copy1);
        copy1.remove(s);
        copy2.append(s);
    
    return copy2;
    
print(select_sort([1,2,74,3,74,3,74,6,7,4]));