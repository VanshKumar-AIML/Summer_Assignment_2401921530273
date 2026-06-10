#include<iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;           // sizes initial

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j])           // if equal increment i 
            i++;
        j++;            // increment j everytime to end while loop
    }

    return i == s.size();           // checking subsequence size (if equal then true)
}

int main() {
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s,t);

    return 0;
}