// Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-score-words-formed-by-letters
 *  RUNTIME: 5 ms
 *  MEMORY: 43.9 MB
 *  DATE: 5-24-2024, 9:22:01 AM
 *
 */

// Solution:

class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        Map<Character, Integer> lettersCounter = new HashMap<>();
        for (char letter : letters) {
            lettersCounter.put(letter, lettersCounter.getOrDefault(letter, 0) + 1);
        }
        int[] totalScore = new int[1];
        explore(words, lettersCounter, score, 0, 0, totalScore);
        return totalScore[0];
    }

    private void explore(String[] words, Map<Character, Integer> letterCounter, int[] score, int index, int currScore,
            int[] totalScore) {
        totalScore[0] = Math.max(totalScore[0], currScore);
        if (index == words.length) {
            return;
        }
        for (int i = index; i < words.length; i++) {
            Map<Character, Integer> tmpCounter = new HashMap<>(letterCounter);
            String word = words[i];
            int wordScore = 0;
            boolean isValid = true;

            for (char ch : word.toCharArray()) {
                if (tmpCounter.getOrDefault(ch, 0) > 0) {
                    tmpCounter.put(ch, tmpCounter.get(ch) - 1);
                    wordScore += score[ch - 'a'];
                } else {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                explore(words, tmpCounter, score, i + 1, currScore + wordScore, totalScore);
            }
        }
    }
}
