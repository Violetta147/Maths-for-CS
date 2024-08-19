
#ifndef PRIME_H
#define PRIME_H

#include <vector>
#include <cmath>

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }

    return true;
}

std::vector<int> *PrimeFactorize(int n)
{
    std::vector<int> p,e;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            if (n % i == 0) //loai bo cac so nguyen to khong phai la thua so cua n
            {
                int count = 0;
                while (n % i == 0)
                {
                    n /= i;
                    count++;
                }
                p.push_back(i);
                e.push_back(count);
            }
        }
    }
    std::vector<int> *result = new std::vector<int>[2];
    result[0] = p;
    result[1] = e;
    return result;
}

int numFactors(std::vector<int> expo)
{
    int numOfFactors = 1;
    for (int i = 0; i < expo.size(); i++)
    {
        numOfFactors *= expo[i] + 1;
    }
    return numOfFactors;
}

int* factorList(int numOfFactors, std::vector<int> p, std::vector<int> e)
{
    int* factors = new int[numOfFactors];
    factors[0] = 1;
    int i = 1;
    int tempExpo[e.size()]{0};
    while (i < numOfFactors)
    {
        int factor = 1;
        int j = e.size() -1;
        while (tempExpo[j] == e[j])
        {
            tempExpo[j] = 0;
            j--;
        }
        tempExpo[j]++;
        for(int k = 0; k < p.size(); k++)
        {
            factor *= (int)pow(p[k], tempExpo[k]);
        }
        factors[i] = factor;
        i++;
    }
    return factors;
}
int sigma(std::vector<int> p, std::vector<int> e)
{
    int sum = 1;
    for (int i = 0; i < p.size(); i++)
    {
        sum *= (int)(pow(p[i], e[i] + 1) - 1) / (p[i] - 1);
    }
    return sum;
}
#endif // PRIME_H