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

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == nullptr)         // base case (execution completed)
        return false;

    if(root->left == nullptr && root->right == nullptr)
        return targetSum==root->val;        // if finded target sum

    int rm = targetSum - root->val;     // remainder

    return hasPathSum(root->left, rm) || hasPathSum(root->right, rm);           // BFS recursive call  
}

int main() {
    // Created TreeNodes :
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int t = 5;              // target sum

    cout << hasPathSum(root,t);         // function called

    return 0;
}