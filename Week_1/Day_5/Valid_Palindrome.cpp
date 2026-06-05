#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
    string str = "" ;
    for(int i=0; i<s.length(); i++)               // convert sentence to single string
        if(isalnum(s[i]))
            str += tolower(s[i]);

            
    int l=0,r=str.length()-1;   // two pointer approach
    while(l<r) {
        if(str[l]!=str[r]) {            // if not equal then false
            return false;
        }
        l++;
        r--;
    }
    return true;            // completed execution (true)
}

int main() {
    string str = "race a car";
    cout << isPalindrome(str);

    return 0;
}