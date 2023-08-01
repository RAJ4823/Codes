// Link: https://leetcode.com/problems/simplify-path

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: simplify-path
 *  RUNTIME: 7 ms
 *  MEMORY: 10.7 MB
 *  DATE: 4-12-2023, 9:41:55 PM
 *
 */

// Solution:

class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        stack<string>s;
        string ans="", str="";

        if(path[n-1] != '/') path+='/', n++;

        for(int i=1; i<=n; i++) {
            if(path[i]=='/'){
                if(str=="" || str=="."){
                    str="";
                    continue;
                }
                
                if(str=="..") {
                    if(!s.empty()) s.pop();
                }
                else{
                    s.push(str);
                }
                str="";
            }
            else{
                str.push_back(path[i]);
            }
        }
        
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
        if(ans.length()==0) ans="/";
        return ans;
    }
};
