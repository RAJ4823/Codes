// Link: https://leetcode.com/problems/house-robber-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: house-robber-iii
 *  RUNTIME: 0 ms
 *  MEMORY: 44.1 MB
 *  DATE: 5-15-2024, 6:23:01 PM
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
    public int[] traverse(TreeNode root) {
        if(root == null) return new int[]{0, 0};

        int left[] = traverse(root.left);
        int right[] = traverse(root.right);

        int[] curr = new int[2];
        // nottake
        curr[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);

        // take
        curr[0] = root.val + left[1] + right[1];

        return curr;
    }

    public int rob(TreeNode root) {
        int ans[] = traverse(root);
        return Math.max(ans[0], ans[1]);
    }
}
