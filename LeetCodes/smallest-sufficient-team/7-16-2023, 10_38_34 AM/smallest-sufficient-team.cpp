// Link: https://leetcode.com/problems/smallest-sufficient-team

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-sufficient-team
 *  RUNTIME: 142 ms
 *  MEMORY: 65.9 MB
 *  DATE: 7-16-2023, 10:38:34 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> ans;
    int total_people, total_skills;

    bool valid(int &mask, vector<int> team) {
        if(mask == (1 << total_skills) - 1) {
            if(ans.size() == 0 || ans.size() > team.size()) {
                return true;
            }
        }
        return false;
    }
    void find(int i, int mask, vector<int> &team, vector<int> &people_skill, vector<vector<int>> &dp) {
        if(i == total_people) {
            if(valid(mask, team)) ans = team;
            return;
        }

        if(dp[i][mask] != -1 && dp[i][mask] <= team.size()) return;

        find(i+1, mask, team, people_skill, dp);
        team.push_back(i);
        find(i+1, mask | people_skill[i], team, people_skill, dp);
        team.pop_back();

        if(team.size() > 0)  dp[i][mask] = team.size();
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        total_people = people.size();
        total_skills = req_skills.size();

        unordered_map<string, int> skill_bits; 
        vector<int> people_skill(total_people);
        vector<vector<int>> dp(total_people, vector<int> (1 << total_skills, -1));

        for(int i=0; i < total_skills; i++) {
            skill_bits[req_skills[i]] = (1 << i);
        }

        for(int i=0; i < total_people; i++) {
            int bits = 0;
            for(auto &str: people[i]) {
                if(skill_bits.count(str) > 0) {
                    bits |= skill_bits[str];
                }
            }
            people_skill[i] = bits;
        }

        vector<int> team;
        find(0, 0, team, people_skill, dp);
        return ans;
    }
};
