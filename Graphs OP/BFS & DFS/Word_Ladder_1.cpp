//? https://practice.geeksforgeeks.org/problems/word-ladder/1
//? https://leetcode.com/problems/word-ladder/
//* HARD PROBLEM

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //! Using bruteforce technique with BFS algorithm
    //? TC = O(wordLength * ListSize * 26 * set_operation_time{1 or logN} )

    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
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

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends