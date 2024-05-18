// Link: https://leetcode.com/problems/remove-k-digits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-k-digits
 *  RUNTIME: 24 ms
 *  MEMORY: 45.7 MB
 *  DATE: 4-11-2024, 2:02:36 PM
 *
 */

// Solution:

class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();

        for(char dig: num.toCharArray()) {
            while(!st.isEmpty() && k > 0 && st.peek() > dig) {
                st.pop();
                k--;
            }
            st.push(dig);
        } 

        while(!st.isEmpty() && k > 0) {
            st.pop();
            k--;
        }

        StringBuilder res = new StringBuilder();
        while(!st.isEmpty()) {
            res.append(st.pop());
        }
        res.reverse();
        
        while(res.length() > 0 && res.charAt(0) == '0') {
            res.deleteCharAt(0);
        }
        
        return res.length() > 0 ? res.toString() : "0";
    }
}
