#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

bool has[MAX+1][2];

bool search(int x)
{
    if(x >= 0) {
        if(has[x][0] == 1) {
            return true;
        } else {
            return false;
        }
    }
    
    x = abs(x);
    if(has[x][1] == 1)
        return true;
    
    return false;
}

void insert(int *a, int n)
{
    for(int i = 0; i < n; i++) {
        if(a[i] >= 0) {
            has[a[i]][0] = 1;
        } else {
            has[abs(a[i])][1] = 1;
        }
    }
}


int main(int argc, char** argv)
{
    int a[] = { -1, 9, -5, -8, -5, -2 };
    int n = sizeof(a)/sizeof(a[0]);
    insert(a, n);
    
    if(search(6) == true)
        cout << "Present" << endl;
    else
        cout << "Non Present" << endl;
    
    
    if(search(-5) == true)
        cout << "Present" << endl;
    else
        cout << "Non Present" << endl;
    
    
    if(search(9) == true)
        cout << "Present" << endl;
    else
        cout << "Non Present" << endl;
    
    return 0;
}