// Link: https://leetcode.com/problems/add-one-row-to-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-one-row-to-tree
 *  RUNTIME: 1 ms
 *  MEMORY: 44.5 MB
 *  DATE: 4-16-2024, 12:51:34 PM
 *
 */

// Solution:

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        Queue<TreeNode> q = new LinkedList<>();
        
        if(depth - 1 == 0) {
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        
        q.add(root);
        depth--;

        while(!q.isEmpty()) {
            int size = q.size();

            while(size > 0) {
                TreeNode node = q.remove();

                if(depth - 1 == 0) {
                    TreeNode leftNewNode = new TreeNode(val);
                    TreeNode rightNewNode = new TreeNode(val);
                    leftNewNode.left = node.left;
                    rightNewNode.right = node.right;
                    node.left = leftNewNode;
                    node.right = rightNewNode;
                }

                if(node.left != null)
                    q.add(node.left);
                if(node.right != null)
                    q.add(node.right);
                size--;
            }

            depth--;
        }
        return root;
    }
}
