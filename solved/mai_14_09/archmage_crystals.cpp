#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;
    long long sum = 0;
    long long temp;
    for (int i=0; i<n; ++i) {
        cin >> temp;
        sum += temp;
    }
    
    long long result = n-1;
    for (int i=0; i<n; ++i) {
        if (sum % (n-i) == 0) {
            result = i;
            break;
        }
    }
    cout << result << '\n';
    return 0;
}

/*
In the high halls of Numeria, an archmage tends to n
magic crystals with powers a1,a2,…,an.
With a fusion spell, he may pick any two crystals with powers x
and y, remove them, and create a single crystal of power x+y.
Each spell reduces the number of crystals by 1.

The archmage seeks harmony: he wants the average power of the crystals to become an integer.
What is the minimum number of spells he must cast?

inp:
4
5 2 3 5
out:
1

inp:
5
11 12 13 14 15
out:
0

*/