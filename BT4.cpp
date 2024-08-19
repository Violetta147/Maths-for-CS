#include <iostream>
#include "library/prime.h"

using namespace std;

long long prodOfFactor(int n, int numOfFactors)
{
    return (long long)pow(n, numOfFactors / 2);
}

int main()
{
    int n;
    cout<<"Vui long nhap n: ";
    cin>>n;
    vector<int> *result = PrimeFactorize(n);
    vector<int> p = result[0];
    vector<int> e = result[1];

    int numOfFactors = numFactors(e);
    cout<<"Tich cac uoc so cua "<<n<<" la: "<<prodOfFactor(n, numOfFactors)<<endl;
    return 0;    
}