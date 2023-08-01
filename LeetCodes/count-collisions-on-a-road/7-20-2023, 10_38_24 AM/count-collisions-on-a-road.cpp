// Link: https://leetcode.com/problems/count-collisions-on-a-road

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-collisions-on-a-road
 *  RUNTIME: 78 ms
 *  MEMORY: 22.2 MB
 *  DATE: 7-20-2023, 10:38:24 AM
 *
 */

// Solution:

class Solution {
public:
    int countCollisions(string dirs) {
        vector<char> v;
        int count = 0;
        for(auto &dir: dirs) {
            if(dir == 'L') {
                if(v.empty()) continue;

                count += (v.back() == 'R') ? 2 : 1;
                v.back() = 'S';
                v.push_back('S');
            } else {
                v.push_back(dir);
            }
        }

        int is_stay = false;
        for(int i = v.size() - 1; i>=0; i--) {
            if(v[i] == 'S') {
                is_stay = true;
            }
            if(is_stay && v[i] == 'R') {
                count++;
            }
        }
        return count;
    }
};
