#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;        // answer vector

    if(!root)           // base case -> execution completed 
        return ans;

    queue<TreeNode*> q;         // queue for saving root in level order
    q.push(root);

    while(!q.empty()) {
        int ls = q.size();          // level size
        vector<int> cl;             // current level storage

        for(int i=0; i<ls; i++) {
            TreeNode* node = q.front();     // from front storage
            q.pop();
            cl.push_back(node->val);        // node value stored

            if(node->left)          // saving nodes in queue
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        ans.push_back(cl);          // push back current level vector
    }

    return ans;
}

int main() {
    // Tree nodes created :
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);             // function called 

    for(int i=0; i<res.size(); i++)                 // display result(answer)
        for(int j=0; j<res[0].size(); j++)
            cout << res[i][j] << " ";      

    return 0;
}