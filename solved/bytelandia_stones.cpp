#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;
    long long array[n];
    long long k = 0;
    for (int i=0; i<n; ++i) {
        cin >> array[i];
        k += array[i];
    }
    long long total_sum = n * (n+1) * k;
    for (int j=0; j<n; j++) {
        total_sum -= (n-j-1)*(n-j) * (array[n-j-1] + array[j]);
    }

    total_sum /= 2;
    cout << total_sum << '\n';
    
    return 0;
}

//link: https://codeforces.com/gym/106063/problem/B