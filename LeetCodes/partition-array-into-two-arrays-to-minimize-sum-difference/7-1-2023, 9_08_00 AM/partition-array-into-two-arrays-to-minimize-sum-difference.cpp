// Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: partition-array-into-two-arrays-to-minimize-sum-difference
 *  RUNTIME: 714 ms
 *  MEMORY: 96.4 MB
 *  DATE: 7-1-2023, 9:08:00 AM
 *
 */

// Solution:

class Solution {
public:
    void fill(vector<int> &nums, int i, int k, int sum, vector<vector<int>> &sums){
        if(i == nums.size()){
            sums[k].push_back(sum);
            return;
        }
        fill(nums,i+1,k,sum,sums);
        fill(nums,i+1,k+1,sum+nums[i],sums);
    }
    
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        
        vector<int> arr1;
        vector<int> arr2;
        
        for(int i=0;i<nums.size();i++){
            if(i<n){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            } 
        }
        
        vector<vector<int>> part1(n+1);
        vector<vector<int>> part2(n+1);
        
        fill(arr1,0,0,0,part1);      
        fill(arr2,0,0,0,part2);

        for(auto &vec: part2){
            sort(vec.begin(),vec.end());  // for binary searching
        }
        
        int res=INT_MAX;
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        for(int k=0;k<=n;k++){
            vector<int> P1=part1[k];
            vector<int> P2=part2[n-k];  
            for(auto val: P1){
                auto itr=lower_bound(P2.begin(),P2.end(),sum/2-val); 
                
                if(itr != P2.end()){
                    int sum1 = val+*itr;
                    int sum2 = sum-sum1;
                    res=min(res,abs(sum1-sum2));
                }
                
                if(itr != P2.begin()){
                    itr--;  
                    int sum1 = val+*itr;
                    int sum2 = sum-sum1;
                    res=min(res,abs(sum1-sum2));
                }
            }
        }
        return res;
    }
};
