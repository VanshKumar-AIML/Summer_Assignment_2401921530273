#include<iostream>
#include<vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> c(26,0);       // char mapping

    for(int i=0; i<magazine.size(); i++) 
        c[magazine[i]-'a']++;       // counting char

    for(int i=0; i<ransomNote.size(); i++) 
        if(--c[ransomNote[i]-'a'] < 0)            // subtracting count 
            return false;               // if less than zero then not in both 

    return true;
}

int main() {
    string r = "aa";
    string m = "aab";
    cout << canConstruct(r,m);
    return 0;
}