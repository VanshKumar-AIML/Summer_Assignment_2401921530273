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

int b(TreeNode* node, int &diameter) {          // BFS function 
    if (!node) return 0;

    int leftHeight = b(node->left, diameter);       // Recursive call
    int rightHeight = b(node->right, diameter);

    // Update diameter: longest path through this node
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height of current node
    return 1 + max(leftHeight, rightHeight);    
}

int diameterOfBinaryTree(TreeNode* root) {      // diameter function called
    int d = 0;
    b(root, d);        // BFS function called
    return d;
}

int main() {
    // Created tree nodes :
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameterOfBinaryTree(root);             // function called
    return 0;
}