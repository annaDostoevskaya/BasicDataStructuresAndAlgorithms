#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class DoubleHash
{
    int *hashTable;
    int curr_size;
    int TABLE_SIZE;
    int PRIME;
    
public:
    
    bool isFull()
    {
        return (curr_size == TABLE_SIZE);
    }
    
    int hash1(int key)
    {
        return (key % TABLE_SIZE);
    }
    
    int hash2(int key)
    {
        return (PRIME - (key%PRIME));
    }
    
    DoubleHash(int _TABLE_SIZE, int _PRIME)
    {
        hashTable = new int[_TABLE_SIZE];
        TABLE_SIZE = _TABLE_SIZE;
        PRIME = _PRIME;
        curr_size = 0;
        for(int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = -1;
        }
    }
    
    int insertHash(int key)
    {
        
        if(isFull())
            return -1;

        int index1 = hash1(key);

        if(hashTable[index1] != -1) {
            int index2 = hash2(key);
            int i = 0;
            while(1) {
                int newIndex = (index1 + i * index2) % TABLE_SIZE;
                if(hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        } else {
            hashTable[index1] = key;
        }
        curr_size++;
        return 0;
    }
    
    void displayHash()
    {
        for(int i = 0; i < TABLE_SIZE; i++) {
            if(hashTable[i] != -1) {
                cout << i << " --> "
                     << hashTable[i] << endl;
            } else {
                cout << i << endl;
            }
        }
    }
};


int main(int argc, char **argv)
{
    int a[] = { 19, 27, 36, 10, 64, 55, 85, 97, 34, 96, 77, 22, 4 };
    int n = sizeof(a)/sizeof(a[0]);
    
    DoubleHash h(13, 7);

    for(int i = 0; i < n; i++)
        h.insertHash(a[i]);
    
    h.displayHash();
    
    return 0;
}