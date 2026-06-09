#include<iostream>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> cm(128, -1);        // char map

    int ml = 0;     // max length
    int l=0;            // left pointer
    int r=0;

    while(r<s.length()) {
        char cc = s[r];         // current char

        if(cm[cc] >= l)
            l = cm[cc]+1;
        
        cm[cc] = r;             // last seen index updated
        ml = max(ml, r-l+1);            // update max length
        r++;            // increment
    }

    return ml;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);

    return 0;
}