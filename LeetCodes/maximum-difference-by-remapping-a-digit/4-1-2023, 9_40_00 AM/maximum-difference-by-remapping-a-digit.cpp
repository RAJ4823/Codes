// Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-difference-by-remapping-a-digit
 *  RUNTIME: 4 ms
 *  MEMORY: 6 MB
 *  DATE: 4-1-2023, 9:40:00 AM
 *
 */

// Solution:

class Solution {
public:
    int minMaxDifference(int number) {
        string num1 = to_string(number);
        string num2 = to_string(number);
        
        char ch1 = num1[0], ch2 = num1[0];
        int n = num1.size();
        
        for(int i=0; i < n; i++)
        {
            if(num1[i]!='9'){
                ch1 = num1[i];
                break;
            }
        }
        
        for(int i=0; i < n; i++)
            if(num1[i] == ch1) 
                num1[i]='9';
        
        for(int i=0; i < n; i++)
            if(num2[i] == ch2) 
                num2[i]='0';
        
        return (stoi(num1)- stoi(num2));
    }
};
