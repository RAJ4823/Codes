// Link: https://leetcode.com/problems/replace-words

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: replace-words
 *  RUNTIME: 696 ms
 *  MEMORY: 55.3 MB
 *  DATE: 6-7-2024, 11:05:25 AM
 *
 */

// Solution:

class Solution {
    public String replaceWords(List<String> dict, String sentence) {
        Set<String> s = new HashSet<>(dict);
        List<String> temp = new ArrayList<>(Arrays.asList(sentence.split(" ")));
        
        StringBuilder res = new StringBuilder();
        
        for (String t : temp) {
            int i = 0;
            while (i <= t.length()) {
                String curr = t.substring(0, i);
                if (s.contains(curr)) {
                    res.append(curr).append(" ");
                    break;
                }
                i++;
            }
            if (i == t.length() + 1) {
                res.append(t).append(" ");
            }
        }
        
        res.deleteCharAt(res.length() - 1); 
        return res.toString();
    }
}
