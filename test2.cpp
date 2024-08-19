#include <iostream>
#include <vector>
using namespace std;

vector<int> sieveOfEratosthenes(int N) {
    vector<bool> isPrime(N+1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p*p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p*p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
    for (int p = 2; p <= N; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

vector<int> markNonPrimes(const vector<int>& primes, int N) {
    vector<int> smallestPrimeFactor(N+1, 0);
    for (int prime : primes) {
        for (int multiple = 2*prime; multiple <= N; multiple += prime) {
            if (smallestPrimeFactor[multiple] == 0) {
                smallestPrimeFactor[multiple] = prime;
            }
        }
    }
    return smallestPrimeFactor;
}

int main() {
    int N;
    cin >> N;
    vector<int> primes = sieveOfEratosthenes(N);
    vector<int> smallestPrimeFactor = markNonPrimes(primes, N);

    // Output the smallest prime factor of each number
    for (int i = 2; i <= N; ++i) {
        if (smallestPrimeFactor[i] == 0) { // Prime number
            cout << i << " is prime" << endl;
        } else {
            cout << i << " is not prime, smallest prime factor: " << smallestPrimeFactor[i] << endl;
        }
    }

    return 0;
}