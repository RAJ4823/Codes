// Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-words-that-can-be-formed-by-characters
 *  RUNTIME: 33 ms
 *  MEMORY: 20.6 MB
 *  DATE: 12-2-2023, 8:39:40 PM
 *
 */

// Solution:

class Solution {
    public:
        int countCharacters(vector<string>& words, string chars) {
                vector<int> counts(26, 0);
                        
                                // Step 1: Initialize Character Counts Array
                                        for (char ch : chars) {
                                                    counts[ch - 'a']++;
                                                            }

                                                                    int result = 0;

                                                                            // Step 3: Check Words
                                                                                    for (const std::string& word : words) {
                                                                                                if (canForm(word, counts)) {
                                                                                                                // Step 4: Calculate Lengths
                                                                                                                                result += word.length();
                                                                                                                                            }
                                                                                                                                                    }

                                                                                                                                                            return result;
                                                                                                                                                                }

                                                                                                                                                                    bool canForm(const std::string& word, std::vector<int>& counts) {
                                                                                                                                                                            std::vector<int> c(26, 0);

                                                                                                                                                                                    // Step 2: Update Counts Array
                                                                                                                                                                                            for (char ch : word) {
                                                                                                                                                                                                        int x = ch - 'a';
                                                                                                                                                                                                                    c[x]++;
                                                                                                                                                                                                                                if (c[x] > counts[x]) {
                                                                                                                                                                                                                                                return false;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                            return true;
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                };



        



