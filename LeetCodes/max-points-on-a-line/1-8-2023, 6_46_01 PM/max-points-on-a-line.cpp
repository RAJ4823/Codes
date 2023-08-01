// Link: https://leetcode.com/problems/max-points-on-a-line

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-points-on-a-line
 *  RUNTIME: 27 ms
 *  MEMORY: 13.4 MB
 *  DATE: 1-8-2023, 6:46:01 PM
 *
 */

// Solution:

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i = 0; i < points.size(); i++){
            int same = 1;
            unordered_map<double, int> count;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    same++;
                }
                else if(points[i][0] == points[j][0]){
                    count[INT_MAX]++;
                }
                else{
                    double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    count[slope]++;
                }
            }
            int ans = 0;
            for(auto &val: count) {
                ans = max(ans, val.second);
            }
            ans += same;
            result = max(result, ans);
        }
        return result;
    }
};
