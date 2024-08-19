#include <iostream>
#include <vector>

using namespace std;

vector<int> eratosthenesRange(int K, int N)
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
    return sieve;
}

int main()
{
    int K, N;
    cin >> K >> N;
    vector<int> sieve = eratosthenesRange(K, N);
    for (int i = 0; i <= N - K; i++)
    {
        cout << i + K << " " << sieve[i] << endl;
    }
    return 0;
}
