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

TreeNode* searchBST(TreeNode* root, int val) {
    if (root==nullptr)      // always condition
        return nullptr;

    if(val==root->val)      // answer
        return root;

    if(val < root->val)     // Recursive steps
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

int main() {
    // Created BST nodes :
    TreeNode* h = new TreeNode(4);
    h->left = new TreeNode(2);
    h->right = new TreeNode(5);
    h->left->left = new TreeNode(1);
    h->left->right = new TreeNode(3);
    int val = 2;        // value to be searched

    TreeNode* finded = searchBST(h,val);            // function called

    cout << "Address: " << finded << endl;          
    cout << "Value: " << finded->val;

    return 0;
}