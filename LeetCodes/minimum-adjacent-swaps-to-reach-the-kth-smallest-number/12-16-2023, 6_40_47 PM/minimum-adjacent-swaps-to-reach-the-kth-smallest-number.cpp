// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-adjacent-swaps-to-reach-the-kth-smallest-number
 *  RUNTIME: 18 ms
 *  MEMORY: 7 MB
 *  DATE: 12-16-2023, 6:40:47 PM
 *
 */

// Solution:

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string temp = num;
        while(k>0){
            k--;
            next_permutation(num.begin(),num.end());
        }
        
        int res = 0;
        for(int i = 0; i<num.size(); i++){
            if(num[i]!=temp[i]){
                int j = i+1;
                while(num[i]!=temp[j] and j<num.size()) j++;
                while(j>i){
                    swap(temp[j], temp[j-1]);
                    j--;
                    res++;
                }
            }
        }
        return res;
    }
};
