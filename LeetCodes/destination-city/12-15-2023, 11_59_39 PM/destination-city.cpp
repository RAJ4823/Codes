// Link: https://leetcode.com/problems/destination-city

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: destination-city
 *  RUNTIME: 14 ms
 *  MEMORY: 10.9 MB
 *  DATE: 12-15-2023, 11:59:39 PM
 *
 */

// Solution:

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;

        // Collect outgoing cities
        for (const auto& path : paths) {
            cities.insert(path[0]);
        }

        // Find destination city with no outgoing path
        for (const auto& path : paths) {
            const std::string& dest = path[1];
            if (cities.find(dest) == cities.end()) {
                return dest;
            }
        }

        return "";
    }
};
