// Link: https://leetcode.com/problems/flatten-nested-list-iterator

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flatten-nested-list-iterator
 *  RUNTIME: 0 ms
 *  MEMORY: 15 MB
 *  DATE: 10-20-2023, 8:09:47 PM
 *
 */

// Solution:

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    private:
        stack<NestedInteger> s; // Stack to hold the nested integers
            
            public:
                NestedIterator(vector<NestedInteger> &nestedList) {
                        // Push all elements of the input list onto the stack in reverse order
                                for (int i = nestedList.size() - 1; i >= 0; i--) {
                                            s.push(nestedList[i]);
                                                    }
                                                        }
                                                            
                                                                int next() {
                                                                        int result = s.top().getInteger();
                                                                                s.pop();
                                                                                        return result;
                                                                                            }
                                                                                                
                                                                                                    bool hasNext() {
                                                                                                            // Keep popping until we find an integer or the stack is empty
                                                                                                                    while (!s.empty()) {
                                                                                                                                if (s.top().isInteger()) {
                                                                                                                                                return true;
                                                                                                                                                            }
                                                                                                                                                                        vector<NestedInteger> nestedList = s.top().getList();
                                                                                                                                                                                    s.pop();
                                                                                                                                                                                                for (int i = nestedList.size() - 1; i >= 0; i--) {
                                                                                                                                                                                                                s.push(nestedList[i]);
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                            return false;
                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                };




        

        



/**
 * Your NestedIte
 * NestedIterator i(nestedList);

*/
