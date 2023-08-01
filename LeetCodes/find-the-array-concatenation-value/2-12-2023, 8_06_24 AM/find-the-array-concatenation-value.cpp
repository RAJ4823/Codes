// Link: https://leetcode.com/problems/find-the-array-concatenation-value

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-array-concatenation-value
 *  RUNTIME: 4 ms
 *  MEMORY: 9.4 MB
 *  DATE: 2-12-2023, 8:06:24 AM
 *
 */

// Solution:

class Solution {
public:
    long long concat(int a, int b) {
        string s = to_string(b);
        long long num = a*pow(10, s.size()) + b;
        return num;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        int i = 0, j = n - 1;
        
        while(i < j) {
            long long num = concat(nums[i], nums[j]);
            sum += num;
            i++;
            j--;
        }
        if(i == j) {
            sum += nums[i];
        }
        return sum;
    }
};
