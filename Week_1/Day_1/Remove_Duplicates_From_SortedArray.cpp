#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) 
        return 0;

    int j = 0; // index of last unique element

    for(int i = 1; i < nums.size(); i++) 
        if(nums[i] != nums[j]) {
            j++;                // update index 
            nums[j] = nums[i];  // removed duplicate
        }

    return j + 1; // length of unique array
}

int main() {
    vector<int> nums = {1,1,2};     
    cout << removeDuplicates(nums);
    return 0;
}