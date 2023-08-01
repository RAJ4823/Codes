// Link: https://leetcode.com/problems/number-of-even-and-odd-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-even-and-odd-bits
 *  RUNTIME: 4 ms
 *  MEMORY: 7.3 MB
 *  DATE: 3-23-2023, 9:25:08 AM
 *
 */

// Solution:

class Solution {
public:
    string bin = "";
    void toBinary(int n)
    {
        if (n / 2 != 0) {
            toBinary(n / 2);
        }
        bin += to_string(n % 2);
    }
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        toBinary(n);
        reverse(bin.begin(), bin.end());
        cout << bin << endl;
        for(int i=0; i<bin.size(); i++) {
            if(bin[i] == '1') {
                ans[i%2]++;
            }
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};
