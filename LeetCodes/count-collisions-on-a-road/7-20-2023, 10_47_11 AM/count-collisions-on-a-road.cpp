// Link: https://leetcode.com/problems/count-collisions-on-a-road

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-collisions-on-a-road
 *  RUNTIME: 51 ms
 *  MEMORY: 16.3 MB
 *  DATE: 7-20-2023, 10:47:11 AM
 *
 */

// Solution:

class Solution {
public:
    int countCollisions(string dirs) {
        int n = dirs.size(), count = 0;
        int left = 0, right = n-1;
        while(left < n && dirs[left] == 'L') left++;
        while(right >=0 && dirs[right] == 'R') right--;

        while(left < right) {
            if(dirs[left] != 'S') count++;
            if(dirs[right] != 'S') count++;
            left++;
            right--;
        }
        if(left == right && dirs[left] != 'S') count++;
        return count;
     }
};
