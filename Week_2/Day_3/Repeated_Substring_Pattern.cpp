#include<iostream>
using namespace std;

bool repeatedSubstringPattern(string s) {
    string d = s + s;           // double string trick

    // check if s exists in double (from first to last char)
    return d.substr(1,d.size()-2).find(s) != string::npos ;
}

int main() {
    string s = "abcabcabc";
    cout << repeatedSubstringPattern(s);
    
    return 0;
}