// Link: https://leetcode.com/problems/add-digits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-digits
 *  RUNTIME: 69 ms
 *  MEMORY: 44.1 MB
 *  DATE: 4-26-2023, 9:40:30 AM
 *
 */

// Solution:

/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    return 1 + (num - 1) % 9;
};
