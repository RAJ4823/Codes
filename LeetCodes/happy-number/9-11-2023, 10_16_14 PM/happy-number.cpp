// Link: https://leetcode.com/problems/happy-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: happy-number
 *  RUNTIME: 5 ms
 *  MEMORY: 6.4 MB
 *  DATE: 9-11-2023, 10:16:14 PM
 *
 */

// Solution:

class Solution {
public:
    int nextNumber(int n){
        int newNumber = 0;
        while(n){
            int num = n % 10;
            newNumber += num*num;
            n /= 10;
        }
        return newNumber;
    }
    
    bool isHappy(int n) {
        unordered_set<int> set;

        while(n != 1 && !set.count(n)){
            set.insert(n);
            n = nextNumber(n);
        }

        return n == 1;
    }
};
