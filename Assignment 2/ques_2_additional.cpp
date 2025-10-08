// COPIED FROM ChatGPT

/*String Split Challenge
You are given a string consisting of lowercase English alphabets. Your task is to determine
if it's possible to split this string into three non-empty parts (substrings) where one of
these parts is a substring of both remaining parts*/

#include <bits/stdc++.h>
using namespace std;

bool isSub(const string &s1, const string &s2) {
    return s2.find(s1) != string::npos;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    bool ok = false;

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);
            string c = s.substr(j);

            // check if any one part is substring of both others
            if ((isSub(a, b) && isSub(a, c)) ||
                (isSub(b, a) && isSub(b, c)) ||
                (isSub(c, a) && isSub(c, b))) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }

    cout << (ok ? "YES" : "NO");
    return 0;
}
