// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-elements-with-maximum-frequency
 *  RUNTIME: 3 ms
 *  MEMORY: 42 MB
 *  DATE: 4-10-2024, 6:35:56 PM
 *
 */

// Solution:

class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int maxi = 0;
        for(int num: nums) {
            mp.put(num, mp.getOrDefault(num, 0) + 1);
            maxi = Math.max(maxi, mp.get(num));
        }

        int cnt = 0;
        for(var entry: mp.entrySet()) {
            int currFreq = entry.getValue();
            if(currFreq == maxi) {
                cnt++;
            }
        }

        return maxi * cnt;
    }
}
