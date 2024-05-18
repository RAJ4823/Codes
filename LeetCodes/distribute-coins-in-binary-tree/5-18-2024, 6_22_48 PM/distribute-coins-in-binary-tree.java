// Link: https://leetcode.com/problems/distribute-coins-in-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: distribute-coins-in-binary-tree
 *  RUNTIME: 0 ms
 *  MEMORY: 41.8 MB
 *  DATE: 5-18-2024, 6:22:48 PM
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
    public int find(TreeNode node, TreeNode par) {
        if(node == null) return 0;
        int moves = find(node.left, node) + find(node.right, node);
        int coins = node.val - 1;
        if(par != null) par.val += coins;
        moves += Math.abs(coins);
        return moves;
    }

    public int distributeCoins(TreeNode root) {
        return find(root, null);
    }
}
