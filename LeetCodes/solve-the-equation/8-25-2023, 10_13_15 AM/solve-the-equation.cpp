// Link: https://leetcode.com/problems/solve-the-equation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: solve-the-equation
 *  RUNTIME: 0 ms
 *  MEMORY: 6.1 MB
 *  DATE: 8-25-2023, 10:13:15 AM
 *
 */

// Solution:

class Solution {
public:
    bool isNum(char &ch) {
        return (ch >= '0' && ch <= '9');
    }
    bool isSign(char &ch) {
        return (ch == '+' || ch == '-');
    }
    string solveEquation(string str) {
        int coeff = 0, sum = 0;
        int n = str.size(), i = 0, mul = 1;
        while(i < n) {
            if(str[i] == '=') {
                mul = (-1);
            }
            else if(str[i] == 'x') {
                coeff += mul;
            }
            else {
                int num = 0, sign = 1;
                if(isSign(str[i])) {
                    sign = (str[i] == '+') ? 1 : -1;
                    i++;
                }

                bool  flag = false;
                while(i < n && isNum(str[i])) {
                    int dig = (str[i] - '0');
                    num += dig;
                    num *= 10;
                    i++;
                    flag = true;
                }
                if(flag) num /= 10;
                else num = 1;
                
                num = (sign * mul * num);

                if(str[i] == 'x') {
                    coeff += num;
                } else {
                    sum += num;
                    if(i != n) i--;
                }
            }
            i++;
        }
        sum = -sum;
        if(coeff == 0) {
            return (sum == 0) ? "Infinite solutions" : "No solution";
        }

        int ans = (sum / coeff);
        return "x=" + to_string(ans);
    }
};
