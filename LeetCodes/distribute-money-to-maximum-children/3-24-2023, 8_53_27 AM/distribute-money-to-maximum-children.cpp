// Link: https://leetcode.com/problems/distribute-money-to-maximum-children

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: distribute-money-to-maximum-children
 *  RUNTIME: 3 ms
 *  MEMORY: 5.9 MB
 *  DATE: 3-24-2023, 8:53:27 AM
 *
 */

// Solution:

class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0)
            return -1;
        if (money / 7 == children && money % 7 == 0)
            return children;
        if (money / 7 == children - 1 && money % 7 == 3)
            return children - 2;
        return min(children - 1, money / 7);
    }
};
