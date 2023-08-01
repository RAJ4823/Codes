// Link: https://leetcode.com/problems/perfect-rectangle

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: perfect-rectangle
 *  RUNTIME: 143 ms
 *  MEMORY: 35.2 MB
 *  DATE: 2-6-2023, 10:30:12 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    // BL = Bottom_Left Corner
    // BR = Bottom_Right Corner
    // TL = Top_Left Corner
    // TR = Top_Right Corner
    pair<ll,ll> BL = {INT_MAX, INT_MAX}, BR = {0,0};
    pair<ll,ll> TR = {INT_MIN, INT_MIN}, TL = {0,0};
    map<pair<ll,ll>, ll> count;

    bool check_freq() {
        for(auto &[p, c]: count) {
            if(p == BL || p == TR || p == TL || p == BR) {
                if(c != 1) return false;
            }
            else if(c % 2 != 0) return false;
        }
        return true;
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        ll sum_area = 0, total_area = 0;

        for(auto &p: rectangles) {
            if(p[0] <= BL.first && p[1] <= BL.second) BL = {p[0],p[1]};
            if(p[2] >= TR.first && p[3] >= TR.second) TR = {p[2],p[3]};

            sum_area += (abs((ll)p[2]-(ll)p[0]) * abs((ll)p[3]-(ll)p[1]));
    
            count[{p[0], p[1]}]++;
            count[{p[2], p[1]}]++;
            count[{p[0], p[3]}]++;
            count[{p[2], p[3]}]++;
        }

        BR = {TR.first, BL.second};
        TL = {BL.first, TR.second};

        total_area = abs(BL.first - TR.first) * abs(BL.second - TR.second);
        if(check_freq() && (sum_area == total_area))
            return true;
        return false;
    }
};
