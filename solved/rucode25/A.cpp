#include <bits/stdc++.h>
using namespace std;

int solution(long long a, long long b) {
    int res = 0;
    if (a < b) {
        a *= 10;
        res = a / b;
    } else if (a % b == 0) {
            res = 0; 
    } else {
        a -= b * (a / b);
        a *= 10;
        res = a / b;
    }
    return res;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << solution(a, b) << '\n';
    return 0;
}
