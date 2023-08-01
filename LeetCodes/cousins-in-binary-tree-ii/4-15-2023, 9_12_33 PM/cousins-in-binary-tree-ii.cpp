// Link: https://leetcode.com/problems/cousins-in-binary-tree-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: cousins-in-binary-tree-ii
 *  RUNTIME: 807 ms
 *  MEMORY: 300.6 MB
 *  DATE: 4-15-2023, 9:12:33 PM
 *
 */

// Solution:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  map<int, int> sum;
  map<TreeNode *, TreeNode *> par;
  void sumValsBFS(TreeNode *root)
  {
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);

    sum[0] = root->val;
    while (!q.empty())
    {
      depth++;
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        auto node = q.front();
        q.pop();

        if (node->left)
        {
          q.push(node->left);
          sum[depth] += node->left->val;
        }
        if (node->right)
        {
          q.push(node->right);
          sum[depth] += node->right->val;
        }
      }
    }
  }
  void replaceBFS(TreeNode *root)
  {
    int depth = 0;
    queue<TreeNode *> q;
    q.push(root);
    root->val = 0;

    while (!q.empty())
    {
      depth++;
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        auto node = q.front();
        q.pop();
        int leftChild = (node->left) ? node->left->val : 0;
        int rightChild = (node->right) ? node->right->val : 0;
        int curSum = leftChild + rightChild;
        if (node->left)
        {
          q.push(node->left);
          node->left->val = sum[depth] - curSum;
        }

        if (node->right)
        {
          q.push(node->right);
          node->right->val = sum[depth] - curSum;
        }
      }
    }
  }
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    sumValsBFS(root);
    replaceBFS(root);
    return root;
  }
};
