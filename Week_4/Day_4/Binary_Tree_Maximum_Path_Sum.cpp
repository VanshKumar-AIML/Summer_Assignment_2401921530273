#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {                           // structure of tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int  ms;         // global variable (max sum)

int getGain(TreeNode* node) {           // BFS function
    if(!node)
        return 0;

    int lg = max(getGain(node->left), 0);           // calculating max sum
    int rg = max(getGain(node->right), 0);

    int cps = node->val + lg + rg;          // current path sum
    ms = max(ms, cps);              // greedy approach

    return node->val + max(lg, rg);     // calculating max sum (recursive)
}

int maxPathSum(TreeNode* root) {
    ms = INT16_MIN;           // min value initialised
    getGain(root);          // BFS function called
    return ms;              // max sum
}

int main() {
    // Created tree nodes :
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root);           // function called
    return 0;
}