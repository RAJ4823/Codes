// Link: https://leetcode.com/problems/minimum-genetic-mutation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-genetic-mutation
 *  RUNTIME: 0 ms
 *  MEMORY: 6.8 MB
 *  DATE: 2-16-2023, 9:06:23 AM
 *
 */

// Solution:

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> s(bank.begin(), bank.end());
        queue<pair<string,int>> q;
        q.push({startGene, 0});
        if(s.find(startGene) != s.end()) {
            s.erase(startGene);
        }

        char chars[4] = {'A', 'C', 'G', 'T'};

        while(!q.empty()) {
            string currGene = q.front().first;
            int mutation = q.front().second;
            q.pop();

            if(currGene == endGene) return mutation;

            for(int i=0; i<8; i++) {
                string originalGene = currGene;
                for(auto &ch: chars) {
                    currGene[i] = ch;
                    if(s.find(currGene) != s.end()) {
                        q.push({currGene, mutation + 1});
                        s.erase(currGene);
                    }
                }
                currGene = originalGene;
            }
        }
        return -1;
    }
};
