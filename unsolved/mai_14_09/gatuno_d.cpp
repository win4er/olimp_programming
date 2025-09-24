#include<iostream>
#include<cmath>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    long double h1, h2, b;
    long long n;
 
    for (int i=0; i<t; ++i) {
        cin >> h1 >> h2 >> b;
        n = ceil(log(h2/h1)/log((b-1)/b));
        cout << n << '\n';
    }
    return 0;
}
// link: https://codeforces.com/gym/106063/problem/G