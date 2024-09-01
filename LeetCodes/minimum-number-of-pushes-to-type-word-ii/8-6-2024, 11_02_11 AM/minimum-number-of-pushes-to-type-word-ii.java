// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-pushes-to-type-word-ii
 *  RUNTIME: 67 ms
 *  MEMORY: 46 MB
 *  DATE: 8-6-2024, 11:02:11 AM
 *
 */

// Solution:

class Solution {
    public int minimumPushes(String word) {
        Map<Character, Integer> freq = new HashMap<>();
        Map<Integer, List<Character>> freqMap = new TreeMap<>();

        for(char ch: word.toCharArray()) {
            int count = freq.getOrDefault(ch, 0) + 1;
            freq.put(ch, count);
        }

        for(Map.Entry<Character, Integer> e: freq.entrySet()) {
            char ch = e.getKey();
            Integer count = e.getValue();
            freqMap.computeIfAbsent(-count, k -> new ArrayList<>());
            freqMap.get(-count).add(ch);
        }
        
        int ans = 0, pushes = 1, keys = 0;
        for(Map.Entry<Integer, List<Character>> e: freqMap.entrySet()) {
            Integer count = -e.getKey();
            List<Character> charList = e.getValue();
            for(char ch: charList) {
                // System.out.println(count + " --- " + ch);
                ans += (count * pushes);
                keys++;
                if(keys % 8 == 0) {
                    pushes++;
                }
            }
        }

        return ans;
    }
}
