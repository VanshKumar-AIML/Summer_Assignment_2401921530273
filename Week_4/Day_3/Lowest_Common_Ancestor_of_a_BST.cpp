#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q)         // base case (execution complete)
        return root;

    TreeNode* l = lowestCommonAncestor(root->left, p, q);       // BFS call
    TreeNode* r = lowestCommonAncestor(root->right, p, q);

    if(l && r)          // if both exists
        return root;

    return l ? l : r;       // return either one
}

int main() {
    // Tree nodes created :
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    TreeNode* p = root;
    TreeNode* q = root->left;

    TreeNode* ans = lowestCommonAncestor(root, p ,q);           // function called
    cout << "Address: " << ans << endl;     // display result
    cout << "Value: " << ans->val;

    return 0;
}