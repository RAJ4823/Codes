// Link: https://leetcode.com/problems/smallest-string-starting-from-leaf

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-string-starting-from-leaf
 *  RUNTIME: 3 ms
 *  MEMORY: 44.7 MB
 *  DATE: 4-17-2024, 10:14:00 AM
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
        StringBuilder curr = new StringBuilder("");
        return find(curr, root).toString();
    }

    public StringBuilder find(StringBuilder curr, TreeNode root) {
        if(root == null) return curr;
        curr.append((char)(root.val + 97));

        if(root.left == null && root.right == null) return curr.reverse();
        
        StringBuilder left = null, right = null;
        if(root.left != null) {
            left = find(new StringBuilder(curr), root.left);
        } 
        if(root.right != null) {
            right = find(new StringBuilder(curr), root.right);
        }

        if(left != null && right != null) {
            return left.compareTo(right) < 0 ? left : right;
        }
        return left != null ? left : right;
    }

}
