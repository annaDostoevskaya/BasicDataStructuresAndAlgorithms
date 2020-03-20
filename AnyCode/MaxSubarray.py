def find_max_crossing_subarray(A):

    low = 0; 
    mid = (len(A)//2)-1;
    high = len(A);

    left_sum = -6543543486;
    sum = 0;
    for i in list(range(low, mid+1))[::-1]:
        sum = sum+A[i];
        if(sum>left_sum):
            left_sum = sum;
            max_left = i;       ## 1-7: Find max subarray in left part;
            
    right_sum = -6543543486;
    sum = 0;
    for j in range(mid+1, high):
        sum = sum+A[j];
        if(sum>right_sum):
            right_sum = sum;
            max_right = j;      ## 11-17: Find max subarray in right part;

    return max_left, max_right, left_sum+right_sum;



def find_max_subarray(A, low, high):
    if(high == low):
        return low, high, A[low];

    mid = (low+high)//2;

    else:
        
        ll, lh, ls = find_max_subarray(A, low, mid);
        rl, rh, rs = find_max_subarray(A, mid+1, high);
        cl, ch, cs = find_max_crossing_subarray(A);
        
        if(ls >= rs and ls > cs):
            return ll, lh, ls;
            
        elif(rs >= ls and ls >= cs):
            return rl, rh, rs;
            
        else:
            return cl, ch, cs;
            

w = find_max_crossing_subarray([-541,-1458,-15,-15,-51, -8465]);
print(w);