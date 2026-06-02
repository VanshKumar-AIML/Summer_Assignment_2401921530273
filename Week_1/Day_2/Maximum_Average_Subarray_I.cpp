#include<iostream>
#include<vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double avg, sum=0 ;        // average and sum

    for(int i=0; i<k; i++)        // total sum
        sum += nums[i];
      
    avg = sum/(double)k;            // average
      
    for(int i=0; i<nums.size()-k; i++){   // sliding window approach
    sum += nums[k+i]-nums[i];

    if(avg < (sum/(double)k) )      // finding max average
        avg = sum/(double)k;
  }

    return avg;
}

int main() {
    int k = 4;                      // frame length
    vector<int> nums = {1,12,-5,-6,50,3};       // array

    cout << findMaxAverage(nums,k) ;
    return 0;
}