// Link: https://leetcode.com/problems/bulb-switcher

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: bulb-switcher
 *  RUNTIME: 3 ms
 *  MEMORY: 5.9 MB
 *  DATE: 4-27-2023, 10:00:41 AM
 *
 */

// Solution:

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
        // int size = 100;
        // vector<vector<int>> m(size+1, vector<int> (size+1, 0));
        // vector<int> on(size+1, 0);
        // for(int i=1; i<=size; i++) {
        //     cout << i << " = ";
        //     for(int j=1; j<=size; j++) {
        //         if(j%i == 0) {
        //             m[i][j] = !m[i-1][j];
        //         } else {
        //             m[i][j] = m[i-1][j];
        //         }
        //         if(j <= i) {
        //             cout << m[i][j] << ' ';
        //             on[i] += m[i][j];
        //         }
        //     }
        //     cout << endl;
        // }
        // for(int i=1; i<=size; i++) {
        //     cout << i << " = " << on[i] << endl;
        // }
        // return 0;
    }
};
