#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int mA = 0;         // max area
    int l = 0, r = height.size()-1;

    while(l<r) {        // two pointer approach
        int mh = min(height[l],height[r]);  // min height

        int cA = (r-l)*mh; // current area calculation
        mA = max(mA,cA);       // find max area

        if(height[l]<height[r])     // move forward
            l++;
        else                        // move backwards
            r--;
    }

    return mA;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    
    cout << maxArea(height) ;

    return 0;
}