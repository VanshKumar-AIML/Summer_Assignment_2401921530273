#include<iostream>
using namespace std;

struct TreeNode {               // Structure of binary tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if(root == nullptr)         // base case condition
        return 0;
    
    int lh = maxDepth(root->left);      // heights in both directions
    int rh = maxDepth(root->right);     // recursive call

    return 1 + max(lh,rh);      // recursive call
}

int main() {
    // Tree nodes created :
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxDepth(root);         // function called

    return 0;
}