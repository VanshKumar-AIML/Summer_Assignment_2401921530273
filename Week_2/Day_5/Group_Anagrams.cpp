#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    if (strs.empty())           // empty edge case
        return {};

    unordered_map<string, vector<string>> ansMap;       // unordered map to store pair

    for (string s : strs) {
        int count[26] = {0};            // counter array
        for (char c : s)  
            count[c - 'a']++;       // count chars in s from strs

        string key;             // variable to store string
        for (int i = 0; i < 26; i++) 
            key += "#" + to_string(count[i]);       // use seperator '#' and make key string
        
        ansMap[key].push_back(s);           // assign key in map for 's' string
    }

    vector<vector<string>> result;
    for (auto& p : ansMap)          // iterate over all pairs from ansMap
        result.push_back(move(p.second));       // push str in ans vector
    
    return result;              // return vector of vector of strings which are anagrams
}

int main() {
    vector<string> srs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string> > ans = groupAnagrams(srs);
    
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}