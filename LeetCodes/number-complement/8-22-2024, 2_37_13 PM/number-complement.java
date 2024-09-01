// Link: https://leetcode.com/problems/number-complement

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-complement
 *  RUNTIME: 1 ms
 *  MEMORY: 40.2 MB
 *  DATE: 8-22-2024, 2:37:13 PM
 *
 */

// Solution:

class Solution {
    public int findComplement(int num) {
        String binaryString = Integer.toBinaryString(num);
        StringBuilder complementString = new StringBuilder();
        for (int i = 0; i < binaryString.length(); i++) {
            int temp = binaryString.charAt(i) - '0';  // Convert character to integer
            temp = temp ^ 1;  // Flip the bit (0 becomes 1, 1 becomes 0)
            complementString.append(temp);  // Append the flipped bit to the result
        }
        return Integer.parseInt(complementString.toString(), 2);
    }
}
