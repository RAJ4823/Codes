// Link: https://leetcode.com/problems/sort-the-students-by-their-kth-score

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-the-students-by-their-kth-score
 *  RUNTIME: 74 ms
 *  MEMORY: 27.3 MB
 *  DATE: 1-22-2023, 8:12:44 AM
 *
 */

// Solution:

class Solution {
public:
    void SortRows(vector<vector<int>>& v,int col)
    {
        bool stay = true;
        int n = v.size();
        int m = v[0].size();
        for (int i = 0; i< n;i++)
        {
            if(stay)
            {
                stay = false;
                for(int j=0;j<n-1;j++)
                {
                    if(v[j][col] < v[j+1][col])
                    {
                        v[j].swap(v[j+1]);
                        stay = true;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        SortRows(score, k);
        return score;
    }
};
