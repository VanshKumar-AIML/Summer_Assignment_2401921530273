#include<iostream>
#include<vector>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty())      // empty checking (edge case)
        return "";

    string t = "^#";
    for (int i=0; i<s.length(); i++) {
        t += s[i];              // chars 
        t += '#';               // seperator
    }

    t += "$";           // seperator at end
    int n = t.size();

    vector<int> p(n, 0);     //type conversion
    int c = 0, r = 0;
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * c - i;

        if (i < r) 
            p[i] = min(r - i, p[mirror]);

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) 
            ++p[i];

        if (i + p[i] > r) {
            c = i; 
            r = i + p[i]; 
            }
    }

    int i = 1, best = 1;
    for (int k = 1; k < n - 1; ++k) 
        if (p[k] > best){  
            best = p[k]; 
            i = k; 
        }

    int start = (i - best) / 2;
    return s.substr(start, best);   //pointer function
}

int main() {
    string s = "eweuffffhhhhferf";
    cout << longestPalindrome(s) ;

    return 0;
}