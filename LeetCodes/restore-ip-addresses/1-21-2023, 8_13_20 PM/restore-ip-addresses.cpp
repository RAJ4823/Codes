// Link: https://leetcode.com/problems/restore-ip-addresses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: restore-ip-addresses
 *  RUNTIME: 18 ms
 *  MEMORY: 7 MB
 *  DATE: 1-21-2023, 8:13:20 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> ans;
    bool isValidNum(string &str) {
        int num = 0;
        stringstream ss(str);
        ss >> num;

        if(num > 255) return false;
        return true;
    }
    bool isValidIP(string &str) {
        string s = "";
        int n = str.length();

        for(int i=0; i < n; i++) {
            if(str[i] == '.') {
                if(s[0] == '0' && s.length() > 1)   
                    return false;
                if(!isValidNum(s))                  
                    return false;
                s = "";
            }
            else {
                s.push_back(str[i]);
            }
        }
        return true;
    }

    void find(int i, int dots, string str) {
        if(dots == 3) {
            str.push_back('.');
            if(isValidIP(str)) {
                str.pop_back();
                ans.push_back(str);
            }
            return;
        }
        if(i >= str.length() - 1)   return;

        find(i+1, dots, str);

        string s = "";
        int ch = 0;

        for(int j=0; j<str.length(); j++) {
            s.push_back(str[j]);

            ch++;
            if(str[j] == '.')   ch = 0;

            if(j == i) {
                if(ch > 3)  return;
                s.push_back('.');
                ch = 0;
            }
        }
        
        if(dots == 2 && ch > 3)  return;
        
        find(i+2, dots+1, s);
    }

    vector<string> restoreIpAddresses(string str) {
        int n= str.length();
        find(0, 0, str);
        return ans;    
    }
};
