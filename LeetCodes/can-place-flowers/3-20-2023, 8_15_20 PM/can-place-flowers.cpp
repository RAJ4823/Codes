// Link: https://leetcode.com/problems/can-place-flowers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: can-place-flowers
 *  RUNTIME: 8 ms
 *  MEMORY: 20.4 MB
 *  DATE: 3-20-2023, 8:15:20 PM
 *
 */

// Solution:

class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int N = arr.size(), count = 0;
        for(int i=0; i<N; i++) {
            int left = (i==0)? i: i-1;
            int right= (i==N-1)?i:i+1;
            if(arr[i] == 0) {
                if(arr[left] == 0 && arr[right] == 0) {
                    count++;
                    arr[i] = 1;
                }
            }
        }
        return (count >= n);
    }
};
