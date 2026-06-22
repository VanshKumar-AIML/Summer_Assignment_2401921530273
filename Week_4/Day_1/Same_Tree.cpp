#include<iostream>
using namespace std;

struct TreeNode {                   // Structure of binary tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {     // BFS used
    if(!p && !q)        // completed execution base case
        return true;

    if(!p || !q || p->val != q->val)        // checking for not equal
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);       // mirroring concept in BFS used        
}

int main() {
    // created Tree nodes 
    TreeNode* p = new TreeNode(1);          // Tree-1
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    TreeNode* q = new TreeNode(1);          // Tree-2
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);

    cout << isSameTree(p,q);            // function called

    return 0;
}