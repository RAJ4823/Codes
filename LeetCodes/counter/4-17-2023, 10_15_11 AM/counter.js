// Link: https://leetcode.com/problems/counter

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: counter
 *  RUNTIME: 59 ms
 *  MEMORY: 41.8 MB
 *  DATE: 4-17-2023, 10:15:11 AM
 *
 */

// Solution:

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
