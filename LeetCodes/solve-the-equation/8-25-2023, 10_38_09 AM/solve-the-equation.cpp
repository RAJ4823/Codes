// Link: https://leetcode.com/problems/solve-the-equation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: solve-the-equation
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 8-25-2023, 10:38:09 AM
 *
 */

// Solution:

class Solution {
public:
    bool isNum(char &ch) {
        return (ch >= '0' && ch <= '9');
    }
    int getNum(int sign, string &str, int &i) {
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') sign *= (-1);
            i++;
        }

        int num = 0, flag = 0;
        while(i < str.size() && isNum(str[i])) {
            num += (str[i] - '0');
            num *= 10;
            i++;
            flag = 1;
        }

        if(flag) return sign*(num/10);
        return sign;
    }

    string solveEquation(string str) {
        int coeff = 0, sum = 0;
        int n = str.size(), i = 0, sign = 1;
        while(i < n) {
            if(str[i] == '=') sign = -1;
            else if(str[i] == 'x') coeff += sign;
            else {
                int num = getNum(sign, str, i);
                cout << num << ' ';
                if(str[i] == 'x') coeff += num;
                else sum += num, i--;
            }
            i++;
        }
        sum = -sum;
        if(coeff == 0) return (sum == 0) ? "Infinite solutions" : "No solution";
        return "x=" + to_string(sum / coeff);
    }
};
