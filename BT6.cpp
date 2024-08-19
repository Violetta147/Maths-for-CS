#include <iostream>
#include "library/prime.h"
#include <cmath>

using namespace std;

int ApproximateDensity(int n)
{
    return n / log(n);
}

int main()
{
    int n;
    cout<<  "Vui long nhap n >= 10^6: ";
    cin >> n;
    cout << "Mat do so nguyen to tu 1 den "<< n <<" xap xi: "<< ApproximateDensity(n) << endl;
    return 0;
}

