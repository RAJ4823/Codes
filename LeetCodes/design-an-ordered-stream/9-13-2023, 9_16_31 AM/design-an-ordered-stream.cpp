// Link: https://leetcode.com/problems/design-an-ordered-stream

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-an-ordered-stream
 *  RUNTIME: 103 ms
 *  MEMORY: 85.9 MB
 *  DATE: 9-13-2023, 9:16:31 AM
 *
 */

// Solution:

class OrderedStream {
public:
    string store[1000];
    int ptr = 0;

    OrderedStream(int n) {}
    
    vector<string> insert(int id, string value) {
        store[id-1]=value;
        vector<string>ans;
        while(store[ptr]!=""){
            ans.push_back(store[ptr]);
            ptr++;
        }
        return ans;
    }
};
