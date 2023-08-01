// Link: https://leetcode.com/problems/combinations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: combinations
 *  RUNTIME: 19 ms
 *  MEMORY: 9.9 MB
 *  DATE: 8-1-2023, 9:44:19 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> ans;
    int N, K;
    void find(int i, int j, vector<int> &arr) {
        if(j == K) {
            ans.push_back(arr);
            return;
        }
        if(i == N) return;

        for(int k=i+1; k<=N; k++) {
            arr.push_back(k);
            find(k, j+1, arr);
            arr.pop_back();
        }
    } 
    vector<vector<int>> combine(int n, int k) {
        N = n;
        K = k;
        vector<int> temp;
        find(0, 0, temp);
        return ans;
    }
};
