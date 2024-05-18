// Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-length-of-a-concatenated-string-with-unique-characters
 *  RUNTIME: 282 ms
 *  MEMORY: 129.3 MB
 *  DATE: 1-23-2024, 5:29:18 PM
 *
 */

// Solution:

class Solution {
public:
    unordered_map<string, int> mp; 
    int ans = 0;

    bool isUnique(string &str) {
        unordered_set<char> st(str.begin(), str.end());
        return (st.size() == str.size());
    }
    int find(int i, string s, vector<string> &arr) {
        if(i == arr.size()) {
            ans = max(ans, (int)s.size());
            return ans;
        }

        int not_take = find(i+1, s, arr), take = INT_MIN;
        string str = s + arr[i]; 
        if(isUnique(str)) {
            take = find(i+1, str, arr);
        }

        return max(take, not_take);
    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        find(0, "", arr);
        return ans;
    }
};
