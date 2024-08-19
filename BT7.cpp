#include <iostream>
#include "library/prime.h"

using namespace std;

int* eratosthenes(int n)
{   
    int *sieve = new int[n];
    for (int i = 2; i <= n; i++)
    {
        sieve[i] = 0;
    }
    sieve[0] = sieve[1] = 1;

    for (int x = 2; x*x <= n ; x++) 
    {
        if (sieve[x]) continue;
        for (int u = 2*x; u <= n; u += x)
        {
            sieve[u] = x;
        }
    }
    return sieve;
}

int main()
{
    int n;
    cin >> n;
    int *sieve = eratosthenes(n);
    for (int i = 2; i <= n; i++)
    {   
        cout << i << " " << sieve[i] << endl;
    }
    delete[] sieve; 
    return 0;
}