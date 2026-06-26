#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {                   // structure of tree nodes
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    TreeNode* h(queue<string>& q) {         // helper function
        string s = q.front();       // initial string
        q.pop();
        if(s == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(s));     // string to int converted for node->val
        root->left = h(q);          // BFS recursive call
        root->right = h(q);

        return root;            // return current root
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#,";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;        // queue to save string
        string s;
        stringstream ss(data);      // stream data transfer

        while(getline(ss, s, ','))
            q.push(s);

        return h(q);            // helper function called
    }
};

void preorder(TreeNode* t, vector<int>& r) {
    if(!t)                  // base case (execution completed)
        return ;

    r.push_back(t->val);            // root stored
    preorder(t->left, r);           // left
    preorder(t->right, r);           // right
}

int main() {
    Codec ser, deser;           // objects created

    // created tree nodes :
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    TreeNode* ans = deser.deserialize(ser.serialize(root));         // function called

    vector<int> r;          // storage vector
    preorder(ans, r);                // preorder traversal (root-left-right)
    for(int i=0; i<r.size(); i++)       // display
        cout << r[i] << " ";

    return 0;
}