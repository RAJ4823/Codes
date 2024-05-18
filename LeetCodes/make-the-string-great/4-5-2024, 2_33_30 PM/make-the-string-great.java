// Link: https://leetcode.com/problems/make-the-string-great

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: make-the-string-great
 *  RUNTIME: 3 ms
 *  MEMORY: 42.3 MB
 *  DATE: 4-5-2024, 2:33:30 PM
 *
 */

// Solution:

class Solution {
    public String makeGood(String s) {
        Stack<Character> st = new Stack<>();

        for(int i=0; i<s.length(); i++) {
            if(!st.empty() && Math.abs(s.charAt(i) - st.peek()) == 32) {
                st.pop();
            } else {
                st.push(s.charAt(i));
            }
        }

        StringBuilder sb = new StringBuilder();
        while(!st.empty()) {
            sb.insert(0, st.pop());
        }

        return sb.toString();
    }
}
