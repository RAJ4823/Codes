// Link: https://leetcode.com/problems/minimum-area-rectangle-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-area-rectangle-ii
 *  RUNTIME: 34 ms
 *  MEMORY: 21.1 MB
 *  DATE: 12-21-2023, 10:54:15 AM
 *
 */

// Solution:

class Solution {
public:
    long long hash(const vector<int> &a, const vector<int> &b) {
        return ((long long)(a[0] + b[0]) << 16) + (a[1] + b[1]);
    }
    long long dist(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<long long, vector<tuple<int,int,int,int>>> centerMap;
        long long ans = LONG_LONG_MAX;

        for(auto &a: points) {
            for(auto &b: points) {
                long long center = hash(a, b);
                centerMap[center].emplace_back(a[0], a[1], b[0], b[1]); 
            }
        }

        for(auto &[_, pointsTuple]: centerMap) {
            for(auto &[x1, y1, x2, y2]: pointsTuple) {
                for(auto &[a1, b1, a2, b2]: pointsTuple) {
                    if((a1 - x1) * (a2 - x1) + (b1 - y1) * (b2 - y1) == 0) {
                        long long area = dist(x1, y1, a1, b1) * dist(x1, y1, a2, b2);
                        if(area > 0) {
                            ans = min(ans, area);
                        }
                    }
                }
            }
        }

        return (ans == LONG_LONG_MAX) ? 0 : sqrt(ans);
    }
};
