// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: serialize-and-deserialize-binary-tree
 *  RUNTIME: 56 ms
 *  MEMORY: 40.1 MB
 *  DATE: 2-2-2023, 11:00:04 AM
 *
 */

// Solution:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root) return "X,";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return (to_string(root->val) + "," + left + right);
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;
        for(auto &ch: data)
        {
            if(ch == ',')
            {
                q.push(s);
                s="";
            } else {
                s += ch;
            }
        }
        if(s != "") q.push(s);
        TreeNode* root = parse(q);
        return root;
    }

    TreeNode* parse(queue<string> &q) {
        string s=q.front();
        q.pop();
        if(s == "X") return NULL;

        TreeNode* root = new TreeNode(stoi(s));
        root->left = parse(q);
        root->right= parse(q);

        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
