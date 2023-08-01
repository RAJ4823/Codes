// Link: https://leetcode.com/problems/string-compression

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: string-compression
 *  RUNTIME: 6 ms
 *  MEMORY: 9.1 MB
 *  DATE: 3-2-2023, 8:52:25 AM
 *
 */

// Solution:

class Solution {
public:
    int compress(vector<char>& chars) {
       int i = 0, count = 1;
        for(int j = 1; j <= chars.size(); j++) {
            if(j == chars.size() || chars[j] != chars[j - 1]) {
                chars[i++] = chars[j - 1];  
                if(count >= 2) 
                    for(char digit : to_string(count)) 
                        chars[i++] = digit;
                count = 0;
            }
            count++;
        }
        return i;
    }
};
