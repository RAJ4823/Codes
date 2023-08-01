// Link: https://leetcode.com/problems/flood-fill

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flood-fill
 *  RUNTIME: 14 ms
 *  MEMORY: 14.1 MB
 *  DATE: 5-25-2022, 4:28:42 PM
 *
 */

// Solution:

class Solution {
public:
    
void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>> &image)
{
    int n = image.size();    // rows
    int m = image[0].size(); // collumn
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != oldColor)
        return;

    image[i][j] = newColor;

    dfs(i - 1, j, oldColor, newColor, image);
    dfs(i + 1, j, oldColor, newColor, image);
    dfs(i, j - 1, oldColor, newColor, image);
    dfs(i, j + 1, oldColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int oldColor = image[sr][sc];
    if (oldColor == newColor)
        return image;
    dfs(sr, sc, oldColor, newColor, image);
    return image;
}

};
