// Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-convert-string-i
 *  RUNTIME: 343 ms
 *  MEMORY: 93.8 MB
 *  DATE: 12-24-2023, 6:05:43 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& org, vector<char>& chg, vector<int>& cost) {
        vector<vector<ll>> mat(26, vector<ll> (26, 1e9 + 7));
        for(int i=0; i<26; i++)
            mat[i][i] = 0;
        
        int n = chg.size();
        for(int i=0; i<n; i++) {
            mat[org[i] - 'a'][chg[i] - 'a'] = min(mat[org[i] - 'a'][chg[i] - 'a'], (ll)cost[i]);
        }

        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                for(int k=0; k<26; k++) {
                    mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
                }
            }
        }

        int m = source.size();
        ll ans = 0;
        for(int i=0; i<m; i++) {
            if(mat[source[i] -'a'][target[i]-'a'] < 1e9) {
                ans += mat[source[i] -'a'][target[i]-'a'];
            } else {
                return -1;
            }
        }
        return ans;
    }
};
