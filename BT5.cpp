#include <iostream>
#include "library/prime.h"

using namespace std;

bool checkPerfectUsingEquation(int n)
{
    vector<int> *result = PrimeFactorize(n);
    vector<int> p = result[0];
    vector<int> e = result[1];

    int sum = sigma(p, e);
    return sum == 2 * n;
}

bool checkPerfectUsingSum(int n)
{
    vector<int> *result = PrimeFactorize(n);
    vector<int> p = result[0];
    vector<int> e = result[1];

    int num = numFactors(e);
    int* factors = factorList(num, p, e);

    int sum = 0;
    for (int i = 0; i < num - 1; i++)
    {
        sum += factors[i];
    }
    return sum == n;
}

int main()
{
    int n;
    cout<<"Vui long nhap n: ";
    cin>>n;
    if (checkPerfectUsingEquation(n))
    {
        cout<<n<<" la so hoan hao."<<endl;
    }
    else
    {
        cout<<n<<" khong phai la so hoan hao."<<endl;
    }
    if (checkPerfectUsingSum(n))
    {
        cout<<n<<" la so hoan hao."<<endl;
    }
    else
    {
        cout<<n<<" khong phai la so hoan hao."<<endl;
    }
    return 0;
}