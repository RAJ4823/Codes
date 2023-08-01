// Link: https://leetcode.com/problems/split-with-minimum-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: split-with-minimum-sum
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 3-28-2023, 9:19:36 PM
 *
 */

// Solution:

class Solution {
public:
    int splitNum(int num) {
        string str = to_string(num);
        sort(str.begin(), str.end());
        string s1 = "", s2 = "";
        int n = str.size();
        
        for(int i=0; i<n; i+=2) s1 += str[i];
        for(int i=1; i<n; i+=2) s2 += str[i];
        int sum = stoi(s1) + stoi(s2);
        
        return sum;
    }
};
