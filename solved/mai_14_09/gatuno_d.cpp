#include<iostream>
#include<cmath>
 
using namespace std;

// why prev solution didnt work?
// 1st we need long long cast, which gives us 999 ms
// 2nd we need to avoid long double input, 
// because it wastes a lot of time,
// instead of it just cast it
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    long long h1, h2, b;
 
    for (int i=0; i<t; ++i) {
        cin >> h1 >> h2 >> b;
        cout << (long long)ceil(log((double)h2/(double)h1)/log((double)(b-1)/(double)b)) << '\n';
    }
    return 0;
}
// link: https://codeforces.com/gym/106063/problem/G