// Link: https://leetcode.com/problems/path-crossing

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-crossing
 *  RUNTIME: 0 ms
 *  MEMORY: 7.2 MB
 *  DATE: 12-23-2023, 9:50:16 PM
 *
 */

// Solution:

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_set<string> s;
        s.insert("0-0");
        for(int i=0; i<path.size(); i++) {
            if(path[i] == 'N') 
                y++;
            else if(path[i] == 'E')
                x++;
            else if(path[i] == 'S')
                y--;
            else
                x--;
            
            string key = to_string(x)+'-'+to_string(y);
            if(s.find(key) != s.end())
                return true;
            else
                s.insert(key);
        }
        return false;
    }
};
