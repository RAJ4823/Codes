// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-steps-to-reduce-a-number-in-binary-representation-to-one
 *  RUNTIME: 0 ms
 *  MEMORY: 41.5 MB
 *  DATE: 5-29-2024, 10:46:14 AM
 *
 */

// Solution:

class Solution {
    public int numSteps(String s) {
        int cnt = 0;
        int cary = 0;

        for(int i = s.length()-1; i >= 1; i--){
            int num = s.charAt(i) -'0';
            if(num == 0 && cary == 0){
                cnt++;
            }else if(num == 1 && cary == 1){
                cnt++;
                cary = 1;
            }else{
                cnt += 2;
                cary = 1;
            }
        }
        if(cary == 1)cnt++;
        return cnt;
    }
}
