// Link: https://leetcode.com/problems/convert-the-temperature

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: convert-the-temperature
 *  RUNTIME: 2 ms
 *  MEMORY: 6.5 MB
 *  DATE: 9-18-2023, 6:56:50 PM
 *
 */

// Solution:

class Solution {
public:
    vector<double> convertTemperature(double c) {
        return  {c + 273.15, c * 1.8 + 32.0};
    }
};
