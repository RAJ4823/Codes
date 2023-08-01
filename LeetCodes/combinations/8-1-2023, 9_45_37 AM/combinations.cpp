// Link: https://leetcode.com/problems/combinations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: combinations
 *  RUNTIME: 24 ms
 *  MEMORY: 9.8 MB
 *  DATE: 8-1-2023, 9:45:37 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> ans;
    void find(int i, int j, int &N, int &K, vector<int> &arr) {
        if(j == K) {
            ans.push_back(arr);
            return;
        }
        if(i == N) return;

        for(int k=i+1; k<=N; k++) {
            arr.push_back(k);
            find(k, j+1, N, K, arr);
            arr.pop_back();
        }
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        find(0, 0, n, k, temp);
        return ans;
    }
};
