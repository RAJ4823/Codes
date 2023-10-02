// Link: https://leetcode.com/problems/flipping-an-image

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flipping-an-image
 *  RUNTIME: 0 ms
 *  MEMORY: 9.1 MB
 *  DATE: 9-16-2023, 2:59:52 PM
 *
 */

// Solution:

class Solution {
public:
    void flip(vector<int> &row) {
        int n = row.size();
        int i = 0, j = n - 1;

        while(i < j) {
            swap(row[i++], row[j--]);
        }
    }

    void invert(vector<int> &row) {
        int n = row.size();
        for(int i=0; i<n; i++) {
            row[i] = !row[i];
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i=0; i<n; i++) {
            flip(image[i]);
            invert(image[i]);
        }
        return image;
    }
};
