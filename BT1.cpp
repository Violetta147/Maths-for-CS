#include <iostream>
#include "library/prime.h"

using namespace std;

int main()
{
    int n;
    cout << "Vui long nhap 1 so: ";
    cin >> n;
    vector<int> *result = PrimeFactorize(n);
    vector<int> p = result[0];
    vector<int> e = result[1];
    cout << "Cac thua so nguyen to cua " << n << " la: ";
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i];
        if (e[i] > 1)
        {
            cout << "^" << e[i];
        }
        else 
        {
            cout << "";
        }
        if (i < p.size() - 1)
        {
            cout << " * ";
        }
    }
    cout << endl;
    return 0;
}