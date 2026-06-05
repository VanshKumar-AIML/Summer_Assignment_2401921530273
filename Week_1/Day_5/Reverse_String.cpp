#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int i=0;
    int j=s.size()-1;
    while(i<j) {            // two pointer approach
        char t = s[i];      // swapping till mid
        s[i] = s[j];
        s[j] = t;

        i++;                // manage pointers
        j--;
    }
}

int main() {
    string str = "hello";       // string 
    vector<char> s;             // char array

    for(int i=0; i<str.length(); i++)
        s.push_back(str[i]);

    reverseString(s);           // function called

    for(int i=0; i<s.size(); i++)
        cout << s[i] << " " ;

    return 0;
}