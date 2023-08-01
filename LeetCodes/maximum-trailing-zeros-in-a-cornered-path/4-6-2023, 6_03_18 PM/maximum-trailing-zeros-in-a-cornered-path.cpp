// Link: https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-trailing-zeros-in-a-cornered-path
 *  RUNTIME: 494 ms
 *  MEMORY: 127 MB
 *  DATE: 4-6-2023, 6:03:18 PM
 *
 */

// Solution:

#define vvp vector<vector<pair<int,int>>> 
#define vp vector<pair<int,int>>

class Solution {
public:
    pair<int,int> countFactors(int num) {
        int fives = 0, twoes = 0;
        while(num > 0) {
            if(num % 5 == 0 && num % 2 == 0) {
                fives++;
                twoes++;
                num/=10;
            } else if(num % 5 == 0) {
                fives++;
                num/=5;
            } else if(num % 2 == 0){
                twoes++;
                num/=2;
            } else {
                break;
            }
        }
        pair<int,int> ans = {fives, twoes};
        return ans;
    }
    int count_tz_row(int row, int start, int end, vector<vector<pair<int,int>>> tz) {
        int fives = 0, twoes = 0;
        for(int i = start; i<=end; i++) {
            fives += tz[row][i].first;
            twoes += tz[row][i].second;
        }
        return min(fives, twoes);
    }

    pair<int,int> sum(pair<int,int> &a, pair<int,int> &b) {
        return  {a.first + b.first, a.second + b.second};
    }
    pair<int,int> sub(pair<int,int> &a, pair<int,int> &b) {
        return  {a.first - b.first, a.second - b.second};
    }
    int count_tz(const pair<int,int> &a) {
        return min(a.first, a.second);
    }


    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vvp tz(n, vp (m)), h(n+1, vp (m+1, {0,0})), v(n+1, vp (m+1, {0,0}));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                tz[i][j] = countFactors(grid[i][j]);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                h[i][j+1] = sum(h[i][j], tz[i][j]);
            }
        }

        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                v[i+1][j] = sum(v[i][j], tz[i][j]);
            }
        }

        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                auto h1 = h[i][j], h2 = sub(h[i][m], h[i][j+1]);
                auto v1 = v[i+1][j], v2 = sub(v[n][j], v[i][j]); 
                int case1 = count_tz(sum(v1, h1));
                int case2 = count_tz(sum(v1, h2));
                int case3 = count_tz(sum(v2, h1));
                int case4 = count_tz(sum(v2, h2));
                res = max({res, case1, case2, case3, case4});
            }
        }
        return res;
    }
};
