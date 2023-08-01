// Link: https://leetcode.com/problems/sort-the-jumbled-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-the-jumbled-numbers
 *  RUNTIME: 227 ms
 *  MEMORY: 76.5 MB
 *  DATE: 12-23-2022, 8:04:31 PM
 *
 */

// Solution:

class Solution {
private:
    int decode(int num, vector<int> &mp) {
        int val = 0, mul=1;
        if(num == 0) return mp[0];
        while(num > 0) {
            int dig = num%10;
            num/=10;
            val += (mul*mp[dig]);
            mul*=10;
        }
        return val;
    }
public:
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) {
            int val = decode(nums[i], mp);
            v[i] = {val, i};
        }
        sort(v.begin(), v.end());

        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i] = nums[v[i].second];
        return ans;
    }
};
