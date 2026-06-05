#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty())            // empty edge case
        return "";

    sort(strs.begin(),strs.end());  // sequence (sorted)
    
    string first = strs[0];         // first and last
    string last = strs.back();
    
    string ans = "";
    
    for (int i = 0; i < min(first.size(), last.size()); i++) {      // comparing strings 
        if (first[i] != last[i])        // not equal breaks
            break;
        ans += first[i];                // adding up common letters
    }

return ans;         // final common string
}

int main() {
    vector<string> strs ;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    cout << longestCommonPrefix(strs) ;
    return 0;
}