// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: search-in-rotated-sorted-array-ii
 *  RUNTIME: 5 ms
 *  MEMORY: 14.1 MB
 *  DATE: 8-10-2023, 9:03:36 PM
 *
 */

// Solution:

class Solution {
    public:
        bool search(std::vector<int>& nums, int target) {
                int low = 0, high = nums.size() - 1;

                        while (low <= high) {
                                    int mid = (low + high) / 2;
                                                if (nums[mid] == target) return true;

                                                            if (nums[low] == nums[mid]) {
                                                                            low++;
                                                                                            continue;
                                                                                                        }

                                                                                                                    if (nums[low] <= nums[mid]) {
                                                                                                                                    if (nums[low] <= target && target <= nums[mid]) high = mid - 1;
                                                                                                                                                    else low = mid + 1;
                                                                                                                                                                } else {
                                                                                                                                                                                if (nums[mid] <= target && target <= nums[high]) low = mid + 1;
                                                                                                                                                                                                else high = mid - 1;
                                                                                                                                                                                                            }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                            return false;
                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                };






