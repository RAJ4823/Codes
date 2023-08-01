// Link: https://leetcode.com/problems/fruit-into-baskets

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: fruit-into-baskets
 *  RUNTIME: 195 ms
 *  MEMORY: 71.3 MB
 *  DATE: 2-7-2023, 3:44:51 PM
 *
 */

// Solution:

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int i = 0, j = 0, n = fruits.size();
        while(j < n) {
            count[fruits[j++]]++;
            if(count.size() > 2) {
                count[fruits[i]]--;
                if(count[fruits[i]] == 0)
                    count.erase(fruits[i]);
                i++;
            }
        }
        return (j - i);
    }
};
