// Link: https://leetcode.com/problems/subsets

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: subsets
 *  RUNTIME: 0 ms
 *  MEMORY: 42.7 MB
 *  DATE: 5-21-2024, 10:01:15 AM
 *
 */

// Solution:

class Solution {
    int n;
    public void find(int i, int[] nums, List<Integer> list, List<List<Integer>> ans) {
        ans.add(new ArrayList<>(list));
        
        for(int j=i; j<n; j++) {
            list.add(nums[j]);
            find(j + 1, nums, list, ans);
            list.remove(list.size() - 1);
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        n = nums.length;

        find(0, nums, temp, ans);
        return ans;
    }
}
