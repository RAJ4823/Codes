// Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-smallest-letter-greater-than-target
 *  RUNTIME: 21 ms
 *  MEMORY: 15.9 MB
 *  DATE: 6-9-2023, 8:53:36 AM
 *
 */

// Solution:

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int index = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if(index < letters.size())
            return letters[index];
        return letters[0];
    }
};
