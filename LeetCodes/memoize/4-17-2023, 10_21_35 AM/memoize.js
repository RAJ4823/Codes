// Link: https://leetcode.com/problems/memoize

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: memoize
 *  RUNTIME: 399 ms
 *  MEMORY: 80.2 MB
 *  DATE: 4-17-2023, 10:21:35 AM
 *
 */

// Solution:

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const dp = {};
    return function(...args) {
        return dp[args.join()] ?? (dp[args.join()] = fn(...args));
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
