//? https://leetcode.com/problems/word-ladder-ii/submissions/

#include <bits/stdc++.h>
using namespace std;

//! LEETCODE SOLUTION := (Specially optimized for leetcode)

class Solution
{
    vector<vector<string>> ans;    // For storing final sequences
    unordered_map<string, int> mp; // For storing {string -> level}
private:
    void backtrack(string &word, int len, vector<string> &seq)
    {
        // If level of word is equal to 0 means we arrived at beginWord
        if (mp[word] == 0)
        {
            // reverse the current seq. because its storing list in backword manner
            reverse(seq.begin(), seq.end());
            // push the sequence in the ans 
            ans.push_back(seq);
            // again reverse the seq. because it may use again fot next seq.
            reverse(seq.begin(), seq.end());
        }

        int level = mp[word];

        // find neighbour word (which is present in the map)
        for (int i = 0; i < len; i++)
        {
            char original = word[i];
            for (int ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                // if new_word is present in the map AND the level[new_word] + 1 == level[word]
                if (mp.find(word) != mp.end() && mp[word] + 1 == level)
                {
                    seq.push_back(word);        // push new_word into the current seq
                    backtrack(word, len, seq);  // backtrack for next word
                    // after the complition of backtracking remove the previously pushed word from the seq for next iteration
                    seq.pop_back();             
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &givenList)
    {
        //! STEP 1 : Find the shortest length of the ladder (simillar to word-ladder-1 solution) 
        //! store each word with its level being used in map.
        
        unordered_set<string> wordList(givenList.begin(), givenList.end());
        queue<string> q;

        wordList.erase(beginWord);
        q.push({beginWord});
        mp[beginWord] = 0;          // first level

        int len = beginWord.size();

        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            int level = mp[word];   // level of current word

            if (word == endWord)
                break;

            for (int i = 0; i < len; i++)
            {
                char original = word[i];
                for (int ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;   // changed word will be called as new_word
                    // If new_word is present in wordList
                    if (wordList.find(word) != wordList.end())
                    {
                        q.push(word);           // Push new_word into queue
                        mp[word] = level + 1;   // store (level+1) in the map for new_word
                        wordList.erase(word);   // erase new_word from the wordList
                    }
                }
                word[i] = original; // Change back to original word for next iteration
            }
        }

        // If endWord is present in the map then find the all sequences by step-2

        //! STEP 2 : Backtrack the map and get sequences (ladders) for the solution
        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            backtrack(endWord, len, seq);
        }
        return ans;
    }
};