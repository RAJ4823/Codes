// Link: https://leetcode.com/problems/3sum-closest

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 3sum-closest
 *  RUNTIME: 30 ms
 *  MEMORY: 10.6 MB
 *  DATE: 11-24-2023, 2:43:44 PM
 *
 */

// Solution:

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans;
        int min=INT_MAX;
        for(int i=0;i<n-2;i++){
               int l=i+1, r= n-1;
               while(l<r){
                   int sum =nums[i]+nums[l]+nums[r];
                   if(abs(sum-target)<min){  
                      min=abs(sum-target);
                      ans=sum;
                   }
                   if(sum<target) l++;        
                   else if(sum>target)r--;
                   else {
                       ans=sum;  
                       i=n-2;  
                       break;
                   }
               }
        }
        return ans;
    }
};
