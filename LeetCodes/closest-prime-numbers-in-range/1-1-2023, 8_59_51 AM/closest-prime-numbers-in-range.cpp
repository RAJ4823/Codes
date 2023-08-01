// Link: https://leetcode.com/problems/closest-prime-numbers-in-range

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: closest-prime-numbers-in-range
 *  RUNTIME: 175 ms
 *  MEMORY: 20.2 MB
 *  DATE: 1-1-2023, 8:59:51 AM
 *
 */

// Solution:

class Solution {
    public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1, true);
        for (int p = 2; p * p <= right; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= right; i += p)
                    prime[i] = false;
            }
        }
        prime[1] = false;
        vector<int> arr;
        for (int p = left; p <= right; p++) {
            if (prime[p])   
                arr.push_back(p);
        }
    
        int n = arr.size();
        if(n < 2)  
            return {-1,-1}; 
    
        int diff = INT_MAX;
        vector<int> ans;
        for(int i=0; i<n-1; i++) {
            if(abs(arr[i] - arr[i+1]) < diff) {
                diff = abs(arr[i] - arr[i+1]);
                ans = {arr[i], arr[i+1]};
            }
        }
        return ans;
    }
};
