#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define NIL -1
#define MAX 100

int lookup[MAX];

int recursion_fib(int n)
{
    if(n <= 1)
        return n;
    return recursion_fib(n-1) + recursion_fib(n-2);
}

void _initialize()
{
    int i;
    for(i = 0; i < MAX; i++)
        lookup[i] = NIL;
}

int memoized_fib(int n)
{
    if(lookup[n] == NIL) {
        if(n <= 1)
            lookup[n] = n;
        else 
            lookup[n] = memoized_fib(n - 1) + memoized_fib(n - 2);
    }
    return lookup[n];
}

int table_fib(int n)
{
    int f[n+1];
    int i;
    f[0] = 0;   f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    
    return f[n];
}

int main(int argc, char **argv)
{
    
    printf("recursion fibonacci number [%d]\n", recursion_fib(40));
    
    _initialize();
    printf("memoized fibonacci number [%d]\n", memoized_fib(40));
    
    
    printf("table fibonacci number [%d]\n", table_fib(40));
    
    return 0;
}