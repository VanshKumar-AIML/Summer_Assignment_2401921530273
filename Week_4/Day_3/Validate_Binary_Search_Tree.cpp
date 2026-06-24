#include<iostream>
using namespace std;

struct TreeNode {               // Structure of tree node
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool v(TreeNode* node, long long minVal, long long maxVal) {            // Recursive function
    if (node == nullptr)        // completed execution (base case)
        return true;

    if (node->val <= minVal || node->val >= maxVal)         // checking for false
        return false;
    
    return v(node->left, minVal, node->val) &&          // recursive BFS calls
            v(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    long long a = -9223372036854775807;             // LONG_LONG_MIN value
    return v(root,a,__LONG_LONG_MAX__);            // recursive bool function called
}

int main() {
    // Created Tree nodes :
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    cout << isValidBST(root);           // function called
    
    return 0;
}