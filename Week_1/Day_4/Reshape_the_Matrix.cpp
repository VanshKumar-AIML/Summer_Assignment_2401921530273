#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int n = mat.size(), m = mat[0].size();
        
    // Check if reshaping is possible or not
    if (n * m != r * c) 
        return mat;
        
    // New reshaped matrix
    vector<vector<int>> ans(r, vector<int>(c));
        
    // old coordinates on new coordinates
    for (int i = 0; i < n * m; i++) 
        ans[i / c][i % c] = mat[i / m][i % m];  // flat index approach
        
    return ans; 
}

int main() {
    vector<vector<int>> mat = {{1,2},{3,4}};
    vector<vector<int>> m = matrixReshape(mat,1,4);

    for(int i=0; i<m.size(); i++) {
        for(int j=0; j<m[0].size(); j++)
            cout << m[i][j] << " " ;
        cout << endl ;
    }

    return 0;
}