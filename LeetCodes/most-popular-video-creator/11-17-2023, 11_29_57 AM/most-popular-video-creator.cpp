// Link: https://leetcode.com/problems/most-popular-video-creator

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: most-popular-video-creator
 *  RUNTIME: 296 ms
 *  MEMORY: 126.3 MB
 *  DATE: 11-17-2023, 11:29:57 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = ids.size();
        unordered_map<string, pair<ll,ll>> popularity; // {sum_of_total_views, max_views}
        unordered_map<string, string> minId; 
        ll maxSumViews = 0;

        for(int i=0; i<n; i++) {
            ll sumViews = popularity[creators[i]].first + (ll)views[i];
            ll maxViews = max(popularity[creators[i]].second, (ll)views[i]);
            popularity[creators[i]] = {sumViews, maxViews};

            maxSumViews = max(maxSumViews, sumViews);
        }

        for(int i=0; i<n; i++) {
            ll sumViews = popularity[creators[i]].first;
            ll maxViews = popularity[creators[i]].second;
            if(sumViews == maxSumViews && maxViews == (ll)views[i]) {
                if(!minId.count(creators[i]) || ids[i] < minId[creators[i]]) {
                    minId[creators[i]] = ids[i];
                }
            }
        }

        vector<vector<string>> ans;
        for(auto &[creator, pops]: popularity) {
            if(pops.first == maxSumViews) {
                ans.push_back({creator, minId[creator]});
            }
        }
        return ans;
    }
};
