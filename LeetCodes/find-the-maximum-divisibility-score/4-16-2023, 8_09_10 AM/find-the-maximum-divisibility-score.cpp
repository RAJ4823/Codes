// Link: https://leetcode.com/problems/find-the-maximum-divisibility-score

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-maximum-divisibility-score
 *  RUNTIME: 1066 ms
 *  MEMORY: 30.2 MB
 *  DATE: 4-16-2023, 8:09:10 AM
 *
 */

// Solution:

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& div) {
        sort(div.begin(), div.end());
        int n = nums.size();
        int m = div.size();
        vector<int> score(m, 0);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(nums[j] % div[i] == 0) {
                    score[i]++;
                }
            }
        }
        
        int maxi = 0, index = 0;
        for(int i=0; i<m; i++) {
            if(score[i] > maxi) {
                maxi = score[i];
                index = i;
            }
        }
        return div[index];
    }
};
