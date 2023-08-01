// Link: https://leetcode.com/problems/word-ladder-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: word-ladder-ii
 *  RUNTIME: 11 ms
 *  MEMORY: 9.1 MB
 *  DATE: 12-27-2022, 4:53:56 PM
 *
 */

// Solution:

class Solution {
    vector<vector<string>> ans;     // For storing final sequences
    unordered_map<string, int> mp;  // For storing {string -> level}
private:
    void backtrack(string &word, int len, vector<string> &seq) {
        if(mp[word] == 0) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
        }

        int level = mp[word];
        for(int i=0; i<len; i++) {
            char original = word[i];
            for(int ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word] + 1 == level) {
                    seq.push_back(word);
                    backtrack(word, len, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& givenList) {
        unordered_set<string> wordList(givenList.begin(), givenList.end());
        queue<string> q;
        
        wordList.erase(beginWord);
        q.push({beginWord});
        mp[beginWord] = 0;

        int len = beginWord.size();

        while(!q.empty()) {
            string word = q.front();
            q.pop();
            int level = mp[word];

            if(word == endWord) 
                break;

            for(int i=0; i<len; i++) {
                char original = word[i];
                for(int ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(wordList.find(word) != wordList.end()) {
                        q.push(word);
                        mp[word] = level + 1;
                        wordList.erase(word);
                    }
                }
                word[i] = original;
            }
        }
    
        if(mp.find(endWord) != mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            backtrack(endWord, len, seq);
        }
        return ans;
    }
};
