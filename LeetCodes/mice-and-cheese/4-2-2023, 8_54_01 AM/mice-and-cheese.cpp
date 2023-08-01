// Link: https://leetcode.com/problems/mice-and-cheese

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: mice-and-cheese
 *  RUNTIME: 235 ms
 *  MEMORY: 118.7 MB
 *  DATE: 4-2-2023, 8:54:01 AM
 *
 */

// Solution:

class Solution {
public:
    bool static comp(const pair<int,int> a, const pair<int,int> b) {
        int diff1 = (a.first - a.second);
        int diff2 = (b.first - b.second);
        if(diff1 == diff2) 
            return a.second > b.second;
        return diff1 < diff2;
        
    }
    
    int find1(vector<pair<int,int>> &v, int k) {
        sort(v.begin(), v.end(), comp);
        int ans=0;
        
        for(auto &x: v) {
            if(k > 0) {
                ans += x.second;
                k--;
            } else {
                ans += x.first;
            }
        }
        return ans;
    }
    
    int find2(vector<pair<int,int>> &v,int k) {
        sort(v.begin(), v.end(), comp);
        int ans=0, n = v.size();
        
        for(int i= n-1; i>=0; i--) {
           if(k > 0) {
                ans += v[i].first;
                k--;
            } else {
                ans += v[i].second;
            }
        }
        return ans;
    }
    
    int miceAndCheese(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<pair<int,int>> v1, v2;
        int n = arr1.size();
        
        for(int i=0; i<n; i++) {
            v1.push_back({arr2[i], arr1[i]});
            v2.push_back({arr1[i], arr2[i]});
        }

        return find1(v1, k);
    }
};
