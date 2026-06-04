#include<iostream>
#include<vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int s1 = 0, s2 = 0;             
    int n = mat.size() , m = mat[0].size();

    for(int i=0; i<n; i++)          // finding primary diagonal sum
            s1 += mat[i][i];
        
    for(int i=0; i<m; i++)          // finding secondary diagonal sum
        s2 += mat[m-1-i][i];

    if(n%2==0 && m%2==0)            // if even dimensions then add both sums
        return s1+s2;
    else                            // odd dimensions -> remove common center element from total
        return s1+s2-mat[n/2][m/2];
}

int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    cout << diagonalSum(mat);

    return 0;
}