#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {               // structure of tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) 
        return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;   // flag to control direction

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // find position to insert based on direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left)
                q.push(node->left);
            if (node->right) 
                q.push(node->right);
        }

        result.push_back(level);
        leftToRight = !leftToRight;   // flip direction
    }

    return result;
}

int main() {
    // Created tree nodes :
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);           // function called
    for(int i=0; i<ans.size(); i++)                     // display 
        for(int j=0; j<ans[i].size(); j++)
            cout << ans[i][j] << " ";

    return 0;
}