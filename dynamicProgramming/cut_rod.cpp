#include <stdio.h>


int max(int x, int y)
{
    return x > y ? x : y;
}


int memoized_cut_rod_aux(int *p, int n, int *r)
{
    if(r[n] >= 0) return r[n];
    
    int q = -6581684;
    
    if(n == 0) {
        int q = 0;
    } else {
        for(int i = 0; i <= n; i++)
            q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
    }
    
    r[n] = q;
    return q;
}



int memoized_cut_rod(int *p, int n)
{
    int r[n];
    
    for(int i = 0; i <= n; i++)
        r[i] = -6581684;
    
    return memoized_cut_rod_aux(p, n, r);
}


int bottom_up_cut_road(int *p, int n)
{
    int r[n];
    r[0] = 0;
    
    for(int j = 0; j <= n; j++) {
        int q = -6581684;
        for(int i = 0; i <= j; i++)
            q = max(q, p[i] + r[j-i]);
        r[j] = q;
    }
    
    return r[n];
}


int** extended_bottom_up_cut_rod(int *p, int n)
{
    int r[n], s[n];
    
    for(int j = 0; j <= n; j++) {
        int q = -6581684;
        for(int i = 0; i <= n; i++) {
            if(q < p[i] + r[j-i]) {
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    static int *ptrs[2] = {r, s};
    return ptrs;
}


void print_cut_rod_solution(int *p, int n)
{
    int **ptrs = extended_bottom_up_cut_rod(p, n);
    
    while(n > 0) {
        printf("%d\n", ptrs[1][n]);
        n = n - ptrs[1][n];
    }
}


int main(int argc, char **argv)
{
    
    
    return 0;
}