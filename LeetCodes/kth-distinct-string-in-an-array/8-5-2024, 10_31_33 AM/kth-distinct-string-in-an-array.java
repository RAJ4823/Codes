// Link: https://leetcode.com/problems/kth-distinct-string-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-distinct-string-in-an-array
 *  RUNTIME: 6 ms
 *  MEMORY: 44.2 MB
 *  DATE: 8-5-2024, 10:31:33 AM
 *
 */

// Solution:

class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> count = new HashMap<>();

        for(String str: arr) {
            count.put(str, count.getOrDefault(str, 0) + 1);
        }

        int i = 0;
        for(String str: arr) {
            if(count.get(str) == 1) {
                i++;
            }
            if(i == k) {
                return str;
            }
        }
        return "";
    }
}
