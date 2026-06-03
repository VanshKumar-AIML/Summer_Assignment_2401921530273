#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j=0;            // initial

    for(int i=0;i<nums.size();i++) 
        if(nums[i]!=0) {            // for non-zero in vector
            int t = nums[i];            // swaping nums[i] and nums[j]
            nums[i]=nums[j];
            nums[j]=t;
            j++;            // increase to next index
        }

}

int main() {
    vector<int>  nums = {0,1,0,3,12};
    moveZeroes(nums);

    for(int i=0; i<nums.size(); i++) 
        cout << nums[i] << "  " ;
    return 0;
}