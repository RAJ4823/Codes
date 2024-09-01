// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: create-binary-tree-from-descriptions
 *  RUNTIME: 64 ms
 *  MEMORY: 56 MB
 *  DATE: 7-15-2024, 10:59:31 AM
 *
 */

// Solution:

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     Integer val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(Integer val) { this.val = val; }
 *     TreeNode(Integer val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> mp = new HashMap<>();
        Map<Integer, Integer> par = new HashMap<>();

        for(int[] record: descriptions) {
            Integer parentVal = record[0];
            Integer childVal = record[1];
            Integer isLeft = record[2];
            
            TreeNode parent = mp.getOrDefault(parentVal, new TreeNode(parentVal));
            TreeNode child = mp.getOrDefault(childVal, new TreeNode(childVal));

            
            if(isLeft == 1) {
                parent.left = child;
            } else {
                parent.right = child;
            }

            mp.put(parentVal, parent);
            mp.put(childVal, child);
            
            par.putIfAbsent(parentVal, -1);
            par.put(childVal, parentVal);
        }

        for(Map.Entry<Integer,Integer> entry: par.entrySet()) {
            if(entry.getValue() == -1) {
                return mp.get(entry.getKey());
            }
        }
        return new TreeNode();
    }
}
