#include<iostream>
using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();         // variables

    if (m == 0)                     // Edge cases
        return 0;
    if (n < m) 
        return -1;

    for (int i = 0; i <= n - m; i++) {          // loop over common string  
        int j = 0;
        while (j < m && haystack[i + j] == needle[j])   // conditions to increment j
            j++;
        if (j == m) 
            return i;           // return first index of common substring 
    }

return -1;          // no common substring
}

int main() {
    string h = "leetcode";
    string n = "leeto";
    cout << strStr(h,n) ;

    return 0;
}