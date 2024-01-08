// Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-square-area-by-removing-fences-from-a-field
 *  RUNTIME: 1065 ms
 *  MEMORY: 254 MB
 *  DATE: 12-24-2023, 5:52:07 PM
 *
 */

// Solution:

class Solution {
public:
    int maximizeSquareArea(int n, int m, vector<int>& rows, vector<int>& cols) {
        unordered_set<int> st;
        long long area = -1, mod = 1e9 + 7;

        rows.push_back(1);
        rows.push_back(n);
        cols.push_back(1);
        cols.push_back(m);

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        for(int i=0; i<cols.size() - 1; i++) {
            for(int j=i+1; j<cols.size(); j++) {
                st.insert(cols[j] - cols[i]);
            }
        }

        for(int i=0; i<rows.size() - 1; i++) {
            for(int j=i+1; j<rows.size(); j++) {
                long long diff = rows[j] - rows[i];
                if(st.count(diff)) {
                    area = max(area, diff * diff);
                }
            }
        }

        return area % mod;
    }
};
