#include<iostream>
#include<algorithm>
using namespace std;

string reverseWords(string s) {
    int n = s.length(); 
    int st = 0;         // start

    for(int i=0; i<=n; i++) 
        if(s[i]==' ' || i == n) {           // reverse from first space to second space
            reverse(s.begin()+st, s.begin()+i);
            st = i+1;           // increment st
        }

    return s;           // inplace solution
}

int main() {
    string s = "Mr Ding";
    cout << reverseWords(s) ;

    return 0;
}