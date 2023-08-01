// Link: https://leetcode.com/problems/minimum-additions-to-make-valid-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-additions-to-make-valid-string
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 4-16-2023, 8:44:56 AM
 *
 */

// Solution:

class Solution
{
public:
  int find(string &word, int n)
  {
    char ch = 'a';
    int count = 0, i = 0;
    while (i < n)
    {
      if (word[i] == ch) i++;
      else count++;

      if (ch == 'c')      ch = 'a';
      else if (ch == 'b') ch = 'c';
      else                ch = 'b';
    }
      return count;
  }
  int addMinimum(string word)
  {
    int n = word.size();
    int count = find(word, n);

    if (word[n - 1] == 'b')      count ++;
    else if (word[n - 1] == 'a') count+=2;
    else                         count+=0;

    return count;
  }
};
