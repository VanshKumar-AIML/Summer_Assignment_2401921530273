#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> nmap ;

    for(int i=0; i<nums.size(); i++) {  
        int c = target - nums[i];       // complement

        if(nmap.find(c) != nmap.end()) // finding complement for sum
            return {nmap[c], i};        // return index
            
        nmap[nums[i]] = i;          // update
    }
    return {};                      // for not any sum pair
}

int main() {
    vector<int> nums = {7,6,2,5};
    vector<int> ans = twoSum(nums,9);   // answer datatype is vector
    
    for(int i=0; i<ans.size(); i++) 
        cout << ans[i] << " " ;     // index returned

    return 0;
}