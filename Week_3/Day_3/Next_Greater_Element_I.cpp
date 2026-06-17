#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    vector<int> nge(n, -1);   // Store next greater element for each index in nums2
    stack<int> st;            // Stack to hold indices of nums2

    // Traverse nums2 to compute next greater elements
    for (int i = 0; i < n; i++) {
        // While stack is not empty and current element is greater than element at stack top
        while (!st.empty() && nums2[i] > nums2[st.top()]) {
            nge[st.top()] = nums2[i];  // Assign next greater element
            st.pop();                  // Remove index since we found its NGE
        }
        st.push(i);  // Push current index
    }

    // Prepare result for nums1
    vector<int> result;
    for (int num : nums1) {
        // Find index of num in nums2
        auto it = find(nums2.begin(), nums2.end(), num);
        int idx = distance(nums2.begin(), it);
        result.push_back(nge[idx]);  // Lookup precomputed NGE
    }
    
    return result;
}

int main() {
    vector<int> n1 = {2,4};                 // inputs
    vector<int> n2 = {1,2,3,4};

    vector<int> ans = nextGreaterElement(n1,n2);            // function called
    for(int i=0; i<ans.size(); i++)             // display ans
        cout << ans[i] << " ";

    return 0;
}