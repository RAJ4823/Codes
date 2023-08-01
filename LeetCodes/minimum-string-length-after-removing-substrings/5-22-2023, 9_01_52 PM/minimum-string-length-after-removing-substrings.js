// Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-string-length-after-removing-substrings
 *  RUNTIME: 106 ms
 *  MEMORY: 47.1 MB
 *  DATE: 5-22-2023, 9:01:52 PM
 *
 */

// Solution:

/**
 * @param {string} s
 * @return {number}
 */
var minLength = function(s) {
    while(s != s.replace("AB", "").replace("CD", "")) {
        s = s.replace("AB", "").replace("CD", "");
    }
    return s.length;
};
