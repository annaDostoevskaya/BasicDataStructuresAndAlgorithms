#include <stdio.h>

int* find_max_crossing_subarray(int* A, int low, int mid, int high)
{
    int max_left, max_right;
    
    // find max subarray in left part;
    int left_sum = -65435, sumL = 0;
    for(int i = mid; i >= low; i--){
        sumL = sumL+A[i];
        if(sumL>left_sum){
            left_sum = sumL;
            max_left = i;
        }
    }
    
    // find max subarray in right part;
    int right_sum = -65435, sumR = 0;
    for(int j = mid+1; j <= high; j++){
        sumR = sumR+A[j];
        if(sumR>right_sum){
            right_sum = sumR;
            max_right = j;
        }
    }
    
    static int B[] = {max_left, max_right, left_sum+right_sum};

    for(int i = 0; i <= 2; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
    
    return B;
}

int main(int argc, char** argv)
{
    int array[] = {};
    find_max_crossing_subarray(array, 0, 4, 8);
    

}