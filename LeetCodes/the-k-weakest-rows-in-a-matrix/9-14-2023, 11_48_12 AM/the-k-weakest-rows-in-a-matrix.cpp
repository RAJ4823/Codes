// Link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: the-k-weakest-rows-in-a-matrix
 *  RUNTIME: 10 ms
 *  MEMORY: 11.1 MB
 *  DATE: 9-14-2023, 11:48:12 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_set<int> st;
        vector<int> ans;
        int rows = mat.size(), cols = mat[0].size();
        for(int j=0; j<cols; j++) {
            for(int i=0; i<rows; i++) {
                if(mat[i][j] == 0 && st.find(i) == st.end() && st.size() < k) {
                    st.insert(i);
                    ans.push_back(i);
                }
            }
        }

        for(int i=0; i<rows; i++) {
            if(st.size() < k && st.find(i) == st.end()) {
                st.insert(i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};
