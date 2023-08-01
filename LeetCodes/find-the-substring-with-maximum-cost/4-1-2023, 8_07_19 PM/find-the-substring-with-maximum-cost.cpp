// Link: https://leetcode.com/problems/find-the-substring-with-maximum-cost

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-substring-with-maximum-cost
 *  RUNTIME: 79 ms
 *  MEMORY: 36.7 MB
 *  DATE: 4-1-2023, 8:07:19 PM
 *
 */

// Solution:

class Solution {
public:
    int maxSum(vector<int> &arr, int n)
    {
        int maxi = INT_MIN, curr = 0;
        for (int i = 0; i < n; i++) {
            curr = curr + arr[i];
            if (maxi < curr)
                maxi = curr;

            if (curr < 0)
                curr = 0;
        }
        return max(0, maxi);
    }
    
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> mp;
        int n = s.size(), m = vals.size();
        for(int i=0; i<m; i++) {
            mp[chars[i]] = vals[i];
        }
        
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) != mp.end())  
                arr[i] = mp[s[i]];
            else
                arr[i] = (int)(s[i] - 'a') + 1;
            // cout << arr[i] << ' ';
        }
        return maxSum(arr, n);
    }
};
