//? https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

#include <bits/stdc++.h>
using namespace std;

//! HARDEST PROBLEM I HAVE EVER SEEN 😵‍💫
class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end()); // For storing all wordList's words
        vector<vector<string>> ansLists;                            // For storing final ans sequences/lists
        vector<string> usedWords;                                   // For storing usedWords on previous level
        queue<vector<string>> q;                                    // For storing lists in FIFO manner

        q.push({beginWord});
        int level = 0; // For indicating current level

        while (!q.empty())
        {
            vector<string> list = q.front();
            q.pop();

            // If all the previous level lists had been checked then increase the level by 1
            // And remove the usedWords from set (which are used in previous level)
            if (list.size() > level)
            {
                level++;
                for (auto &word : usedWords)
                    st.erase(word);
            }

            // Last word of the list
            string word = list.back();

            // endWord is matched
            if (word == endWord)
            {
                // If it is first time then push list into the ansLists
                // Else check if the list size equal to the previous ansLists list size
                // Then only push list into the ansLists
                if (ansLists.size() == 0)
                    ansLists.push_back(list);
                else if (ansLists[0].size() == list.size())
                    ansLists.push_back(list);
            }

            // Change each character of word from 'a' to 'z'
            for (int i = 0; i < word.size(); i++)
            {
                // Store original character
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // If new word is exists in the set then
                    // 1. push new word into the current list
                    // 2. push new word into the usedWords
                    // 3. push current list into the queue
                    // 4. pop the new word from current list for next iteration
                    if (st.find(word) != st.end())
                    {
                        list.push_back(word);      // 1
                        usedWords.push_back(word); // 2
                        q.push(list);              // 3
                        list.pop_back();           // 4
                    }
                }
                // change current character back to the original
                word[i] = original;
            }
        }
        return ansLists;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

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
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end(), comp);
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[i].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends