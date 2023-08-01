// Link: https://leetcode.com/problems/word-ladder

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: word-ladder
 *  RUNTIME: 145 ms
 *  MEMORY: 13.9 MB
 *  DATE: 12-3-2022, 10:53:34 AM
 *
 */

// Solution:

class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({startWord, 1});
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                char ch = word[i];
                for (char alpha = 'a'; alpha <= 'z'; alpha++)
                {
                    word[i] = alpha;
                    // Change 'i' th character of word from 'a' to 'z' and check
                    // If edited word exists in set then
                    if (st.find(word) != st.end())
                    {
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                // replace 'i' th charater of the editedWord to original charater for next iteration
                word[i] = ch;
            }
        }
        return 0;
    }
};
