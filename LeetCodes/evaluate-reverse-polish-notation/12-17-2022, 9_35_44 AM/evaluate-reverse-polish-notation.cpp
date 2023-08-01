// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: evaluate-reverse-polish-notation
 *  RUNTIME: 26 ms
 *  MEMORY: 12.2 MB
 *  DATE: 12-17-2022, 9:35:44 AM
 *
 */

// Solution:

#define ll long long
class Solution {
private:
    void calc(stack<ll> &s, string &op) {
        ll num2 = s.top();
        s.pop();
        ll num1 = s.top();
        s.pop();
        if(op == "+") 
            s.push(num1 + num2);
        else if(op == "-")
            s.push(num1 - num2);
        else if(op == "*")
            s.push(num1 * num2);
        else if(op == "/")
            s.push(num1 / num2);
    }
    void eval(stack<ll> &s, string &str) {
        stringstream ss(str);
        ll num = 0;
        ss >> num;
        // cout << num << " ";
        if(str == "+" || str == "-" || str == "*" || str == "/") {
           calc(s, str);
        } else {
            s.push(num);
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> s;
        for(ll i=0; i<tokens.size();i++) {
            eval(s, tokens[i]);
        }
        return s.top();
    }
};
