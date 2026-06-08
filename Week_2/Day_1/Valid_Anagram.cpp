#include<iostream>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())       // edge case
        return false;

    unordered_map<char,int> count;          // map to store count

    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;              // increase count
        count[t[i]]--;              // decrease count
    }

    for (auto &p : count)           // checking pair
        if (p.second != 0)              // net frequency checked
            return false;

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";
    cout << isAnagram(s,t);

    return 0;
}