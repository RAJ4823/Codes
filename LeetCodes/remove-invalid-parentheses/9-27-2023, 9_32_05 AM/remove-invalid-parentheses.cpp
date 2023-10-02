// Link: https://leetcode.com/problems/remove-invalid-parentheses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-invalid-parentheses
 *  RUNTIME: 86 ms
 *  MEMORY: 21.5 MB
 *  DATE: 9-27-2023, 9:32:05 AM
 *
 */

// Solution:

class Solution {
public:
    bool isValid(string str, unordered_set<string> &st) {
        if(st.find(str) != st.end()) return false;

        int cnt = 0;
        for(auto &ch: str) {
            if(ch == '(') cnt++;
            if(ch == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        unordered_map<string, bool> vis;
        unordered_set<string> st;
        queue<string> q;

        bool flag = false;
        q.push(s);

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string curr = q.front();
                q.pop();

                if(isValid(curr, st)) {
                    st.insert(curr);
                    flag = true;
                    continue;
                }

                for(int i = 0; i < curr.size(); i++) {
                    if(curr[i] != ')' && curr[i] != '(') 
                        continue;

                    string next = curr.substr(0, i) + curr.substr(i+1);
                    if(!vis[next]) {
                        q.push(next);
                        vis[next] = true;
                    }
                }
            }

            if(flag) 
                break;
        }
        return vector<string>(st.begin(), st.end());
    }
};
