#include <iostream>
#include "library/prime.h"

using namespace std;

int main(){
    int n;
    cout<<"Vui long nhap n>=1: ";
    cin>>n;
    vector<int> *result = PrimeFactorize(n);
    vector<int> p = result[0];
    vector<int> e = result[1];
    int sum = sigma(p, e);
    cout<<"Tong cac uoc so cua "<<n<<" la: "<<sum<<endl;
    return 0;
}