#include <iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to build tree
TreeNode* Helper(vector<int>& preorder, int preStart, int preEnd,           // backtrack function
                          vector<int>& inorder, int inStart, int inEnd,
                          unordered_map<int,int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) 
        return NULL;

    // Root is always the first element in preorder
    TreeNode* root = new TreeNode(preorder[preStart]);

    // Find root index in inorder
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    // Recursively build left and right subtrees
    root->left = Helper(preorder, preStart+1, preStart+numsLeft,        // recursive calls
                                 inorder, inStart, inRoot-1, inMap);
    root->right = Helper(preorder, preStart+numsLeft+1, preEnd,
                                  inorder, inRoot+1, inEnd, inMap);

    return root;                // return current root
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty() || inorder.empty())             // edge case handled
        return nullptr;

    unordered_map<int,int> inMap;
    for (int i = 0; i < inorder.size(); i++)            // putting values in map
        inMap[inorder[i]] = i;
    
    return Helper(preorder, 0, preorder.size()-1,               // call helper
                           inorder, 0, inorder.size()-1, inMap);
}

// Display tree level by level (for testing)
void displayTree(TreeNode* root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<int> preorder = {3,9,20,15,7};           // inputs
    vector<int> inorder  = {9,3,15,20,7};

    TreeNode* root = buildTree(preorder, inorder);          // function called

    cout << "Tree structure (level order):" << endl;
    displayTree(root);

    return 0;
}
