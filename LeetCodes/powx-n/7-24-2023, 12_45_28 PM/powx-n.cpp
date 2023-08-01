// Link: https://leetcode.com/problems/powx-n

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: powx-n
 *  RUNTIME: 4 ms
 *  MEMORY: 5.9 MB
 *  DATE: 7-24-2023, 12:45:28 PM
 *
 */

// Solution:

class Solution {
    public:
    //i am passing long long here because the value `-2147483648` after abs will cause overflow because int can store max `-2147483647`.so type casting.
        double solve(double x,long long n){
                double ans=1;
                        while(n>0){
                                    int c=n&1;//checking if it is odd then we will multiply  one   extra value of x
                                         
                                                            if(c==1){
                                                                         ans=ans*x;
                                                                                     }
                                                                                                x=x*x;
                                                                                                           n=n>>1;
                                                                                                                   }
                                                                                                                           return ans;
                                                                                                                               }
                                                                                                                                   double myPow(double x, int n) {
                                                                                                                                            if(x == 1) return 1;
                                                                                                                                                     // -2147483648
                                                                                                                                                              double ans=solve(x,abs(n));
                                                                                                                                                                      if(n<0)
                                                                                                                                                                                  return 1/ans;
                                                                                                                                                                                              cout<<INT_MAX;
                                                                                                                                                                                                          return ans;
                                                                                                                                                                                                              }
                                                                                                                                                                                                              };




