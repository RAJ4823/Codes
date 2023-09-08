// Link: https://leetcode.com/problems/kth-largest-element-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-largest-element-in-an-array
 *  RUNTIME: 84 ms
 *  MEMORY: 47.3 MB
 *  DATE: 8-14-2023, 10:51:46 AM
 *
 */

// Solution:

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
                // int n= nums.size();
                        // sort(nums.begin(), nums.end());
                                // return nums[n-k];

                                        priority_queue<int,vector<int>, greater<int>>pq;
                                                for(int i=0;i<k;i++){
                                                            pq.push(nums[i]);
                                                                    }
                                                                            for(int i=k;i<nums.size();i++){
                                                                                        if(nums[i]>pq.top()){
                                                                                                        pq.pop();
                                                                                                                        pq.push(nums[i]);
                                                                                                                                    }
                                                                                                                                            }
                                                                                                                                                    return pq.top();
                                                                                                                                                        }
                                                                                                                                                        };





