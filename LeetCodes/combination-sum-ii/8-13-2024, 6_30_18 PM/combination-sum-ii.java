// Link: https://leetcode.com/problems/combination-sum-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: combination-sum-ii
 *  RUNTIME: 2 ms
 *  MEMORY: 43.2 MB
 *  DATE: 8-13-2024, 6:30:18 PM
 *
 */

// Solution:

class Solution {
    int total, n;
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        n = candidates.length;
        total = target;
        Arrays.sort(candidates);

        find(0, target, candidates, new ArrayList<>(), ans);
        return ans;
    }

    public void find(int i, int sum, int[] arr, List<Integer> list, List<List<Integer>> ans) {
        if(sum == 0) {
            ans.add(new ArrayList<>(list));
            return;
        }
        if(i >= n) return;

        for(int j=i; j<n; j++) {
            if(j > i && arr[j] == arr[j-1]) continue;
            if(arr[j] > sum) break;

            list.add(arr[j]);
            find(j + 1, sum - arr[j], arr, list, ans);
            list.remove(list.size() - 1);
        }
    }
}
