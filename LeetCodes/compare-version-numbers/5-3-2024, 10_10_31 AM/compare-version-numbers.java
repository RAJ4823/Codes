// Link: https://leetcode.com/problems/compare-version-numbers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: compare-version-numbers
 *  RUNTIME: 1 ms
 *  MEMORY: 41.4 MB
 *  DATE: 5-3-2024, 10:10:31 AM
 *
 */

// Solution:

class Solution {
  public int compareVersion(String version1, String version2) {
    var v1 = version1.split("\\.");
    var v2 = version2.split("\\.");

    for (var i=0; i < Math.max(v1.length, v2.length); i++) {
      var num1 = i < v1.length ? Integer.parseInt(v1[i]) : 0;
      var num2 = i < v2.length ? Integer.parseInt(v2[i]) : 0;

      if (num1 < num2) return -1;
      if (num1 > num2) return 1;
    }
    return 0;
  }
}
