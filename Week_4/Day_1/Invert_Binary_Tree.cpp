#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {               // Structure of binary tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void displayTree(TreeNode* root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return ;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } 
            else 
                cout << ". "; // placeholder for null

        }

        cout << endl; // new line for each level
    }

}

TreeNode* invertTree(TreeNode* root) {
    if (!root) 
        return NULL;

    // Swap left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main() {
    // Created tree nodes :
    TreeNode* h = new TreeNode(2);
    h->left = new TreeNode(1);
    h->right = new TreeNode(3);
    cout << "Original Tree : " << endl;             // disply function called
    displayTree(h);
    cout << endl;

    TreeNode* nh = invertTree(h);                   // Invert Tree function called
    cout << "Inverted Tree : " << endl;             // display function called
    displayTree(nh);

    return 0;
}