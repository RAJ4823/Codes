// Link: https://leetcode.com/problems/defanging-an-ip-address

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: defanging-an-ip-address
 *  RUNTIME: 46 ms
 *  MEMORY: 41.4 MB
 *  DATE: 9-16-2023, 3:26:17 PM
 *
 */

// Solution:

/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    return address.replaceAll('.', "[.]");;
};
