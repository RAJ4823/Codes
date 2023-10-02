// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-words-in-a-string-iii
 *  RUNTIME: 67 ms
 *  MEMORY: 48 MB
 *  DATE: 10-1-2023, 11:19:35 AM
 *
 */

// Solution:

var reverseWords = function(s) {
    const words = s.split(' '); 
    for (let i = 0; i < words.length; i++) {
        words[i] = words[i].split('').reverse().join('');
    }
    return words.join(' ');
};
