#include <bits/stdc++.h>

using namespace std;

// to find intersection we have to define max left and min right coords
long long solution(long long s1, long long e1, long long s2, long long e2) {
    long long left, right;
    if (s1 <= s2) {
        left = s2;
    } else {
        left = s1;
    }
    if (e1 <= e2) {
        right = e1;
    } else {
        right = e2;
    }
    long long result = 0;
    if (left <= right) {
        result = right - left;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;
    
    long long a, b, c, d;
    for (int i=0; i<n; ++i) {
        cin >> a >> b >> c >> d;
        cout << solution(a, b, c, d) << '\n';
    }
    return 0;
}

/*
On the Pan-American Highway, two maintenance crews work on different road segments. Each segment is a closed interval on a line (in kilometers). To coordinate resources, we only need the length of the overlap between both segments.

Given two closed intervals [a,b] and [c,d] (with a≤b and c≤d),
print the length of their intersection on the real line.
If they do not overlap (or only touch at a single point), the length must be 0.

The length of a closed interval [x,y] is defined as y−x.

inp:
6
3 7 1 5
0 0 0 0
-5 -1 2 8
1 10 3 6
-1 4 4 10
-10 -2 -7 0

out:
2
0
0
3
0
5

*/