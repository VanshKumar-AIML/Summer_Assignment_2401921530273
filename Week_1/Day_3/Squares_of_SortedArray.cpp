#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) 
        nums[i] = nums[i]*nums[i];      // squared and inplace stored

    std::sort(nums.begin(),nums.end());     // STL for sorted answer
    return nums;
}

int main() {
    vector<int> nums = {-7,-3,2,3,11};
    sortedSquares(nums);
    
    for(int i=0; i<nums.size(); i++) 
        cout << nums[i] << " " ;

    return 0;
}