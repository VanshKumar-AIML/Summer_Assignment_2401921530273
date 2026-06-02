#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int ans = nums[0];      // initial value
    int cmax = nums[0];     // circular max

    for(int i=1; i<nums.size(); i++) {
        cmax = max(nums[i],cmax+nums[i]);   // finding max from sum
        ans = max(ans,cmax);        // max sum
    }
        
    return ans;
}

int main() {
    vector<int> nums = {5,4,-1,7,8};
    cout << maxSubArray(nums);
    return 0;
}