#include<iostream>
#include<vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    int n1 = s.length(), n2 = p.size();         // variables initialised
    if(n2>n1)
        return {};

    vector<int> ans;            // answer
    vector<int> p_c(26,0), window_c(26,0) ;     // counter char map
    for(int i=0; i<n2; i++) {           // count
        p_c[p[i]-'a']++;
        window_c[s[i]-'a']++;
    }

    if(p_c == window_c)         // found at starting
        ans.push_back(0);

    for(int i=n2; i<n1; i++) {
        window_c[s[i]-'a']++;           // add new char
        window_c[s[i-n2]-'a']--;        // remove old char

        if(p_c == window_c)
            ans.push_back(i-n2+1);          // last index of anagram is added
    }

    return ans;
}

int main() {
    string s = "abab";
    string p = "ab";

    vector<int> a = findAnagrams(s,p);
    for(int i=0; i<a.size(); i++)
        cout << a[i] << " " ;

    return 0;
}