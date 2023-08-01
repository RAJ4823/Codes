// Link: https://leetcode.com/problems/count-of-smaller-numbers-after-self

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-of-smaller-numbers-after-self
 *  RUNTIME: 465 ms
 *  MEMORY: 108.1 MB
 *  DATE: 12-25-2022, 6:31:24 PM
 *
 */

// Solution:

#define vpii vector<pair<int, int>>
#define vi vector<int>

class Solution
{
private:
    void mergeSort(int start, int end, vpii &vp, vi &ans, vpii &sorted)
    {
        if (start >= end)   return;

        int mid = start + (end - start) / 2;
        mergeSort(start, mid, vp, ans, sorted);
        mergeSort(mid + 1, end, vp, ans, sorted);
        merge(start, mid, end, vp, ans, sorted);
    }

    void merge(int start, int mid, int end, vpii &vp, vi &ans, vpii &sorted)
    {
        int left = start, right = mid + 1;
        int i = start, countLess = 0;

        while (left <= mid and right <= end)
        {
            if (vp[left] < vp[right])
            {
                ans[vp[left].second] += countLess;
                sorted[i++] = vp[left++];
            }
            else if (vp[left] > vp[right])
            {
                countLess++;
                sorted[i++] = vp[right++];
            }
            else
            {
                left++;
                right++;
            }
        }

        while (left <= mid)
        {
            ans[vp[left].second] += countLess;
            sorted[i++] = vp[left++];
        }

        while (right <= end)
        {
            sorted[i++] = vp[right++];
        }

        for (int i = start; i <= end; i++)
            vp[i] = sorted[i];
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vpii sorted, vp;
        vi ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            vp.push_back({nums[i], i});
            sorted.push_back({nums[i], i});
        }
        mergeSort(0, n - 1, vp, ans, sorted);
        return ans;
    }
};
