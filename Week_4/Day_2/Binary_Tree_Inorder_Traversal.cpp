#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {                   // Structure of Binary Tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void t(TreeNode* node , vector<int>& r) {       // recursive traversal
    if(node==nullptr) return;

    t(node->left,r);        // left
    r.push_back(node->val); // root
    t(node->right,r);       // right
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> r;      // vector used
    t(root,r);      // traversal function called
    return r;      // val returned
}

int main() {
    // Created tree nodes
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = inorderTraversal(root);           // function called
    for(int i=0; i<ans.size(); i++)             // display inorder traversal of tree
        cout << ans[i] << " ";

    return 0;
}