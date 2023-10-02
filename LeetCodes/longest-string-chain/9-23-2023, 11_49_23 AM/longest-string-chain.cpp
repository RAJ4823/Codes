// Link: https://leetcode.com/problems/longest-string-chain

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-string-chain
 *  RUNTIME: 140 ms
 *  MEMORY: 25.7 MB
 *  DATE: 9-23-2023, 11:49:23 AM
 *
 */

// Solution:

class Solution {
public:
    bool isChainWords(string &curr, string &next) {
        int i = 0, j = 0, mismatch = 0;
        while(i < curr.size() && j < next.size()) {
            if(curr[i] == next[j]) {
                i++;
                j++;
            } else {
                mismatch++;
                j++;
            }
        }
        if(j == next.size() - 1) {
            mismatch++;
        }

        if(i == curr.size() && mismatch == 1) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<string>> mp;
        unordered_map<string, int> len;
        queue<string> q;
        sort(words.begin(), words.end());
        for(auto &word: words) {
            int size = word.size();
            mp[size].push_back(word);
            q.push(word);
            len[word] = 1;
        }


        int steps = 1;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string curr = q.front();
                q.pop();

                for(auto &next: mp[curr.size() + 1]) {
                    int newLen = steps + 1;
                    if(isChainWords(curr, next) && newLen > len[next]) {
                        q.push(next);
                        len[next] = newLen;
                    }
                }
            }
            steps++;
        }
        return steps - 1;
    }
};
