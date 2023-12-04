// Link: https://leetcode.com/problems/container-with-most-water

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: container-with-most-water
 *  RUNTIME: 68 ms
 *  MEMORY: 59.4 MB
 *  DATE: 11-24-2023, 2:42:50 PM
 *
 */

// Solution:

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, i = 0, j = height.size() - 1;
        while(i < j) {
            int h = min(height[i], height[j]);
            area = max(area, (j - i) * h);
            while(i < j && height[i] <= h) i++;
            while(i < j && height[j] <= h) j--;
        }
        return area;
    }
};
