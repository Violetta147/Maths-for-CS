#include <iostream>
#include "library/prime.h"

using namespace std;

int main()
{   
    int n;
    cout<<"Vui long nhap so >=1: ";
    cin>>n;
    vector<int> *result = PrimeFactorize(n);
    vector<int> p = result[0];
    vector<int> e = result[1];
    int num = numFactors(e);
    cout<<"So uoc so cua "<<n<<" la: "<<num<<endl;
    int* factors = factorList(num, p, e);
    cout<<"Cac uoc so cua "<<n<<" la: ";
    for (int i = 0; i < num; i++)
    {
        cout<<factors[i];
        if (i < num - 1)
        {
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}