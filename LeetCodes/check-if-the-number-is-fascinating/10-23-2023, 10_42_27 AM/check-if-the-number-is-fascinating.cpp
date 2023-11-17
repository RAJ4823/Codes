// Link: https://leetcode.com/problems/check-if-the-number-is-fascinating

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-the-number-is-fascinating
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 10-23-2023, 10:42:27 AM
 *
 */

// Solution:

class Solution {
public:
    void countDig(int n, int cnt[]) {
        while(n > 0) {
            int d = n % 10;
            cnt[d]++;
            n /= 10;
        }
    }

    bool isValid(int cnt[]) {
        if(cnt[0] > 0) return false;
        for(int i=1; i<10; i++) {
            if(cnt[i] != 1)
                return false;
        }
        return true;
    }
    bool isFascinating(int n) {
        int cnt[10] = {0};
        countDig(n, cnt);
        countDig(n*2, cnt);
        countDig(n*3, cnt);
        return isValid(cnt);
    }
};
