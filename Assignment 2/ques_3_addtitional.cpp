/*String Anagrams
Given two strings str1 and str2, determine if they form an anagram pair.
Note: Two strings are considered anagrams if one string can be rearranged to form the other
string.
*/

#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;

    if(areAnagrams(str1, str2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
