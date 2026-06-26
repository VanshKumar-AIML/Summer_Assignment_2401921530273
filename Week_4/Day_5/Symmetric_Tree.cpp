#include<iostream>
using namespace std;

struct TreeNode {                   // Structure of Tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool ismirror(TreeNode* left, TreeNode *right) {        // checking mirror (symmetry)
    if(left==nullptr && right==nullptr)     // base case
        return true;
    
    if(left==nullptr || right==nullptr || left->val != right->val)      // checking false (unequal)   
        return false;
    
    return ismirror(left->left,right->right) && ismirror(left->right,right->left);      // checking all cases (recursive calls) -> BFS
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr)       // edge case handling
        return true;
    
    return ismirror(root->left,root->right);        // call recursive (BFS) bool function 
}

int main() {
    // Created Tree nodes :
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    cout << isSymmetric(root);          // Function called
    return 0;
}