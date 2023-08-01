// Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-difference-you-can-get-from-changing-an-integer
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 4-17-2023, 10:12:24 AM
 *
 */

// Solution:

class Solution {
public:
    int getMax(string s) {
        int n = s.size();
        char ch = 'x';
        for(int i=0; i<n; i++) {
            if(s[i] != '9' && ch == 'x') {
                ch = s[i];
            } 
            if(s[i] == ch) 
                s[i] = '9';
        }
        cout << s << endl;
        return stoi(s);
    }
    int getMin(string s) {
        int n = s.size();
        char ch = 'x', rep;

        for(int i=0; i<n; i++) {
            if(s[i] != '1' && s[i] != '0' && ch == 'x') {
                ch = s[i];
                rep = (i == 0) ? '1' : '0';
            } 
            if(s[i] == ch) 
                s[i] = rep;
        }
        cout << s << endl;
        return stoi(s);
    }

    int maxDiff(int num) {
        string val = to_string(num);
        int num1 = getMax(val);
        int num2 = getMin(val);
        return num1 - num2;
    }
};
