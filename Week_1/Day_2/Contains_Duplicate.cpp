#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> SN;      // seen numbers (traversed)
        
    for (int num : nums) {
        if (SN.find(num) != SN.end())     // checking duplicate
            return true;
            
        SN.insert(num);            // inserting values if not seen
        }

    return false;           // no duplicate exists
}

int main() {
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2} ; 
    cout << containsDuplicate(nums);    
    return 0;
}