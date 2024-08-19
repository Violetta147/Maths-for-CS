#include <iostream>
#include "library/prime.h"

using namespace std;

vector<int> eratosthenesRange(int K, int N, int &sum, int &product)
{
    vector<int> sieve(N - K + 1, 0);
    for (int x = 2; x * x <= N; ++x)
    {
        if (isPrime(x))
        {
            int start = max(x * x, (K + x - 1) / x * x);
            for (int u = start; u <= N; u += x)
            {
                sieve[u - K] = x;
            }
        }
    }
    if (K == 1)
    {
        sieve[0] = 1;
    }

    for (int i = 0; i <= N - K; i++)
    {
        if (sieve[i] == 0)
        {
            sum += i + K;
            product *= i + K;
        }
    }
    return sieve;
}

int main()
{
    int K, N;
    cin >> K >> N;
    int sum = 0, product = 1;
    vector<int> sieve = eratosthenesRange(K, N, sum, product);
    for (int i = 0; i <= N - K; i++)
    {
        cout << i + K << " " << sieve[i] << endl;
    }
    cout << "Tich cac so nguyen to da tim duoc: " << product << endl;
    cout << "Tong cac so nguyen to da tim duoc: " << sum << endl;
    return 0;
}