#include <bits/stdc++.h>
using namespace std;

int solution(int x, int y, int r) {
    int x_1 = x-r, x_2 = x+r;
    int y_1 = y-r, y_2 = y+r;
    int result = 0;
    if ((x_1 <= 0 && x_2 >= 0) || (y_1 <= 0 && y_2 >= 0)) {
        result += 1;
    }
    if (x_2 > 0 && y_2 > 0) {
        result += 1;
    }
    if (x_1 < 0 && y_2 > 0) {
        result += 1;
    }
    if (x_1 < 0 && y_1 < 0) {
        result += 1;
    }
    if (x_2 > 0 && y_1 < 0) {
        result += 1;
    }
    return result;
}

int main() {
    int x, y, r;
    cin >> x >> y >> r;
    cout << solution(x, y, r) << '\n';
    return 0;
}
