// Link: https://leetcode.com/problems/plus-one

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: plus-one
 *  RUNTIME: 7 ms
 *  MEMORY: 8.9 MB
 *  DATE: 2-15-2023, 8:40:52 AM
 *
 */

// Solution:

class Solution {
public:
   vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      for (int i = n-1; i >= 0; --i) { 
        if (digits[i] == 9) {  
          digits[i] = 0;
        } else {  
          digits[i] += 1;
          return digits;
        }
      }
      digits.push_back(0);
      digits[0] = 1;
      return digits;
    }
};
