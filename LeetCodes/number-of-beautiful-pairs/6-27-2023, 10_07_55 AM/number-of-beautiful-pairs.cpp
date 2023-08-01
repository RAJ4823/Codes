// Link: https://leetcode.com/problems/number-of-beautiful-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-beautiful-pairs
 *  RUNTIME: 595 ms
 *  MEMORY: 161.9 MB
 *  DATE: 6-27-2023, 10:07:55 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> digit(int val) {
        int last = val%10, first = 0;
        while(val > 0) {
            first = val%10;
            val /= 10;
        }
        return {first, last};
    }
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                vector<int> a = digit(nums[i]);
                vector<int> b = digit(nums[j]);
                if(__gcd(a[0], b[1]) == 1) count++;
            }
        }
        return count;
    }
};
