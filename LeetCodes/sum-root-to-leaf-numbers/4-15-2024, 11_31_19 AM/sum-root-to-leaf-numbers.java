// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-root-to-leaf-numbers
 *  RUNTIME: 3 ms
 *  MEMORY: 40.9 MB
 *  DATE: 4-15-2024, 11:31:19 AM
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
    public static int sum;
    public int sumNumbers(TreeNode root) {
        int num = 0;
        sum = 0;
        dfs(num, root);
        return sum;
    }

    public void dfs(int num, TreeNode node) {
        if(node == null) return;
        num = num * 10 + node.val;

        if(node.right == null && node.left == null) {
            System.out.println(num);
            sum += num;
            return;
        }

        dfs(num, node.right);
        dfs(num, node.left);
    }
}
