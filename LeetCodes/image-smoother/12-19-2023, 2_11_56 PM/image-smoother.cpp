// Link: https://leetcode.com/problems/image-smoother

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: image-smoother
 *  RUNTIME: 49 ms
 *  MEMORY: 22 MB
 *  DATE: 12-19-2023, 2:11:56 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    ll getAverage(vector<vector<int>> &img, int i, int j) {
        ll sum = 0, count = 0;
        for(int x=-1; x<=1; x++) {
            for(int y=-1; y<=1; y++) {
                if(i+x < 0 || j+y < 0 || i+x >= img.size() || j+y >= img[0].size()) {
                    continue;
                }
                count++;
                sum += (ll)img[i+x][j+y];
            }
        }
        return sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();

        vector<vector<int>> ans(n, vector<int> (m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = (int)getAverage(img, i, j);
            }
        }
        return ans;
    }
};
