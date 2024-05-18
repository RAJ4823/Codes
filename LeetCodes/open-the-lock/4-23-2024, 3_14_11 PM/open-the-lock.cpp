// Link: https://leetcode.com/problems/open-the-lock

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: open-the-lock
 *  RUNTIME: 287 ms
 *  MEMORY: 140.8 MB
 *  DATE: 4-23-2024, 3:14:11 PM
 *
 */

// Solution:

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> vis, dead(deadends.begin(), deadends.end());

        string start = "0000";

        if(dead.count(start) || dead.count(target))
            return -1;

        q.push(start);
        vis.insert(start);

        int steps = 0;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string str = q.front();
                q.pop();

                if(str == target)
                    return steps;

                vector<string> neighbours = generate_neighbours(str); 
                for(auto nextStr: neighbours) {
                    if(vis.count(nextStr) || dead.count(nextStr))
                        continue;
                    
                    q.push(nextStr);
                    vis.insert(nextStr);
                }
            }
            steps++;
        }

        return -1;
    }

    vector<string> generate_neighbours(string str) {
        vector<string> neighs;

        for(int i=0; i<4; i++) {
            char orgChar = str[i];

            str[i] = (orgChar == '0') ? '9' : (char)(orgChar - 1);
            neighs.push_back(str);

            str[i] = (orgChar == '9') ? '0' : (char)(orgChar + 1);
            neighs.push_back(str);

            str[i] = orgChar;
        }

        return neighs;
    }
};
