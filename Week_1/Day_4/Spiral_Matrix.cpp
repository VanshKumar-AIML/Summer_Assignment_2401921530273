#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int t=0;                   // top
    int b=matrix.size()-1;        // bottom
    int l=0;                   // left
    int r=matrix[0].size()-1;     // right

    while(t<=b && l<=r) {
        for(int i=l; i<=r; ++i) {       // move from left to right
            ans.push_back(matrix[t][i]);    // insert value
        }   t++;                // reduce upwards

        for(int i=t; i<=b; ++i) {       // move from top to bottom
            ans.push_back(matrix[i][r]) ;
        }   r--;                // reduce left

        if(t<=b) {
            for(int i=r; i>=l; --i) {   // move from right to left
                ans.push_back(matrix[b][i]) ;
            } b--;              // reduce bottom

        }

        if(l<=r) {
        for(int i=b; i>=t; --i) {       // move from bottom to top
                ans.push_back(matrix[i][l]);
            } l++;              // increase left
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> s = spiralOrder(matrix);

    for(int i=0; i<s.size(); i++)
        cout << s[i] << " " ;
        
    return 0;
}