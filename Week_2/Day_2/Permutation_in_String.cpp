#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n1=s1.length(), n2=s2.length();     // both string lengths

    if(n1>n2)               // unable to include
        return false;

    vector<int> s1_c(26,0);         // vector map for char count
    vector<int> s2_c(26,0);

    for(int i=0; i<n1; i++) {           // counting chars
        s1_c[s1[i]-'a']++;
        s2_c[s2[i]-'a']++;
    }

    if(s1_c == s2_c)            // if equal then true (inclusion)
        return true;

    for(int i=n1; i<n2; i++) {
        s2_c[s2[i]-'a']++;
        s2_c[s2[i-n1]-'a']--;

        if(s1_c == s2_c)            // permute inclusion
            return true;
    }

    return false;           // execution complete -> false inclusion
}

int main() {
    string s1 = "ab";
    string s2 = "eidboaoo";
    cout << checkInclusion(s1,s2) ;

    return 0;
}