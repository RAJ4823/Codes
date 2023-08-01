// Link: https://leetcode.com/problems/restore-ip-addresses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: restore-ip-addresses
 *  RUNTIME: 3 ms
 *  MEMORY: 6.8 MB
 *  DATE: 1-21-2023, 7:49:59 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> ans;
    bool isValidIP(string &s) {
        int num = 0;
        string temp;
        for(auto &ch: s) {
            if(ch == '.') {
                if(temp[0] == '0' && temp.length() > 1) return false;
                stringstream toNum(temp);
                toNum >> num;
                if(num > 255) return false;
                temp = "";
            }
            else
                temp.push_back(ch);
        }
        if(temp[0] == '0' && temp.length() > 1) return false;
        stringstream toNum(temp);
        toNum >> num;
        if(num > 255) return false;
        
        return true;
    }

    void find(int i, int dots, string str) {
        if(dots == 3) {
            cout << str << endl;
            if(isValidIP(str)) ans.push_back(str);
            return;
        }
        if(i >= str.length() - 1) return;

        find(i+1, dots, str);

        string temp = "";
        int j = 0, k = 0;
        for(auto &ch: str) {
            temp.push_back(ch);

            k++;
            if(ch == '.') k = 0;
            if(j == i) {
                if(k > 3) return;
                temp.push_back('.');
                k = 0;
            }

            j++;
        }
        
        if(dots == 2 && k > 3) return;
        find(i+2, dots+1, temp);
    }

    vector<string> restoreIpAddresses(string s) {
        int n= s.length();
        find(0, 0, s);
        return ans;    
    }
};
