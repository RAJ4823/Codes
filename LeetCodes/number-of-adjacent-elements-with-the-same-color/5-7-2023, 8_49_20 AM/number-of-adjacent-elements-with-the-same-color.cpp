// Link: https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-adjacent-elements-with-the-same-color
 *  RUNTIME: 602 ms
 *  MEMORY: 177.9 MB
 *  DATE: 5-7-2023, 8:49:20 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> arr;
    vector<int> ans;
    int n;
    int find(int i, int val, int diff) {
        if (i > 0 && arr[i - 1] != 0 && arr[i - 1] == arr[i]) {
            val += diff;
        }

        if (i < n - 1 && arr[i + 1] != 0 && arr[i + 1] == arr[i]) {
            val += diff;
        }

        return val;
    }

    vector<int> colorTheArray(int N, vector<vector<int>>& queries) {
        int val = 0;
        n = N;
        arr.resize(n, 0);
        
        for (auto &q: queries) {
            int index = q[0];
            int color = q[1];
            val = find(index, val, -1);
            arr[index] = color;

            val = find(index, val, 1);
            ans.push_back(val);
        }
        
        return ans;
    }
};
