#include <bits/stdc++.h>
using namespace std;

string encode(int t) {
    string result;
    int hh, mm, ss;
    hh = t / 3600;
    mm = (t % 3600) / 60;
    ss = t % 60;
    if (hh < 10) result += '0';
    result += to_string(hh);
    result += ':';
    if (mm < 10) result += '0';
    result += to_string(mm);
    result += ':';
    if (ss < 10) result += '0';
    result += to_string(ss);
    return result;
}

int decode(string t) {
    int hh = stoi(t.substr(0, 2));
    int mm = stoi(t.substr(3, 2));
    int ss = stoi(t.substr(6, 2)); 
    return hh * 3600 + mm * 60 + ss;
}

int main() {
    string t;
    cin >> t;
    if (t.size() == 8) {
        cout << decode(t) << '\n';
    } else {
        cout << encode(stoi(t)) << '\n';
    }
    return 0;
}
