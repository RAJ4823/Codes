// Link: https://leetcode.com/problems/smallest-string-starting-from-leaf

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-string-starting-from-leaf
 *  RUNTIME: 1 ms
 *  MEMORY: 42.8 MB
 *  DATE: 4-15-2024, 11:52:50 AM
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
    String ans;
    public String smallestFromLeaf(TreeNode root) {
        ans = null;
        StringBuilder curr = new StringBuilder("");
        dfs(curr, root);

        return ans;
    }

    public void dfs(StringBuilder curr, TreeNode node) {
        if(node == null) return;
        curr.append((char)(node.val + 97));

        dfs(curr, node.left);
        dfs(curr, node.right);

        if(node.left == null && node.right == null) {
            String temp = curr.reverse().toString();
            if(ans == null || ans.compareTo(temp) > 0) {
                ans = temp;
            }
            curr.reverse();
        }
        curr.deleteCharAt(curr.length() - 1);
    }
}
