#include<iostream>
#include<vector>
using namespace std;

int firstUniqChar(string s) {
    vector<int> c(26,0);            // saving unordered map overhead -> c(letter,count of that letter)

    for(int i=0; i<s.length(); i++) 
        c[s[i]-'a']++;      // counting frequency with vector
                            // ASCII values solved and slot of that letter is updated with count

    for(int i=0; i<s.length(); i++)
        if(c[s[i]-'a']==1)      // checking word with 1 frequency(non-repeating)
            return i;

    return -1;          // all repeating case
}

int main() {
    string s = "aabb";
    cout << firstUniqChar(s) ;

    return 0;
}