// Link: https://leetcode.com/problems/robot-collisions

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: robot-collisions
 *  RUNTIME: 404 ms
 *  MEMORY: 189.1 MB
 *  DATE: 6-27-2023, 10:53:34 AM
 *
 */

// Solution:

class Solution {
public:

    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dirs) {
        int n = pos.size();
        vector<int> index(n), stack;
        for(int i=0; i<n; i++) index[i] = i;
        sort(index.begin(), index.end(), [&](int i, int j) {
            return pos[i] < pos[j];
        });

        for(auto &i: index) {
            if(dirs[i] == 'L') {
                while(!stack.empty() && health[i]) {
                    if(health[i] < health[stack.back()]) {
                        health[stack.back()]--;
                        health[i] = 0;
                    } else {
                        if(health[i] > health[stack.back()]) {
                            health[i]--;
                        } else {
                            health[i] = 0;
                        }

                        health[stack.back()] = 0;
                        stack.pop_back();
                    }
                }
            } else {
                stack.push_back(i);
            }
        }

        vector<int> ans;
        for(auto &h: health) {
            if(h > 0) ans.push_back(h);
        }
        return ans;
    }
};
