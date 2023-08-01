// Link: https://leetcode.com/problems/prime-subtraction-operation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: prime-subtraction-operation
 *  RUNTIME: 26 ms
 *  MEMORY: 25.6 MB
 *  DATE: 3-26-2023, 3:08:31 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getPrimes(int n) {
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<n; i++){
            for(int j=2*i; j<n; j+=i){
                isPrime[j] = false;
            }
        }

        vector<int> primes;
        for(int i=0; i < n; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> primes = getPrimes(1001);
        
        int prev = nums[n-1];
        for(int i= n-2; i>=0; i--) {
            if(nums[i] < prev) {
                prev = nums[i];
                continue;
            }

            bool flag = true;
            for(auto &prime: primes) {
                if(prime >= nums[i]) break;
                
                if(nums[i] - prime < prev) {
                    prev = nums[i]- prime;
                    flag = false;
                    break;
                }
            }

            if(flag) return false;
        }
        return true;
    }
};
