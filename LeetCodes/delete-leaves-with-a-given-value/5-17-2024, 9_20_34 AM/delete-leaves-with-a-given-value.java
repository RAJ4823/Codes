// Link: https://leetcode.com/problems/delete-leaves-with-a-given-value

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: delete-leaves-with-a-given-value
 *  RUNTIME: 0 ms
 *  MEMORY: 44.1 MB
 *  DATE: 5-17-2024, 9:20:34 AM
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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if(root == null) return null;

        root.left = removeLeafNodes(root.left, target);
        root.right = removeLeafNodes(root.right, target);

        if(root.left == null && root.right == null && root.val == target) {
            return null;
        }
        return root;
    }
}
