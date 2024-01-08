// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: substring-with-concatenation-of-all-words
 *  RUNTIME: 1987 ms
 *  MEMORY: 77.1 MB
 *  DATE: 12-8-2023, 7:28:26 PM
 *
 */

// Solution:

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    unordered_map<string, int> m;

    for (int i = 0; i < words.size(); i++) m[words[i]]++;

    int l = 0, r = words[0].length() - 1;
    int wordlength = r - l + 1;

    while (s.length() - l >= words.size() * wordlength) {
      string word = s.substr(l, wordlength);

      if (m[word]) {
        unordered_map<string, int> mp = m;
        mp[word]--;

        int left = l + wordlength, right = r + wordlength, cnt = 1;
        while (right < s.length()) {
          string wd = s.substr(left, wordlength);
          if (mp[wd] > 0) {
            cnt++;
            mp[wd]--;
            left += wordlength;
            right += wordlength;
          } else
            break;
        }
        if (cnt == words.size()) ans.push_back(l);
      }

      l++;
      r++;
    }
    return ans;
  }
};
