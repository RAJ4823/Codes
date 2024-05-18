// Link: https://leetcode.com/problems/open-the-lock

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: open-the-lock
 *  RUNTIME: 106 ms
 *  MEMORY: 46.6 MB
 *  DATE: 4-23-2024, 3:03:43 PM
 *
 */

// Solution:

class Solution {
    public int openLock(String[] deadends, String target) {
        Queue<String> pq = new LinkedList<>();
        Set<String> vis = new HashSet<>();

        Set<String> dead = new HashSet<>();
        dead.addAll(Arrays.asList(deadends));

        String start = "0000";

        if(dead.contains(target) || dead.contains(start))
            return -1;

        pq.add("0000");
        vis.add("0000");

        int steps = 0;
        while(!pq.isEmpty()) {
            int size = pq.size();
            while(size > 0) {
                String str = pq.remove();

                if(str.equals(target)) {
                    return steps;
                }
                
                List<String> neighbours = generate_neighbours(str);
                for(String nextStr: neighbours) {
                    if(dead.contains(nextStr) || vis.contains(nextStr))
                        continue;
                    pq.add(nextStr);
                    vis.add(nextStr);
                }

                size--;
            }
            steps++;
        }
        return -1;
    }

    private Pair<String,Integer> make_pair(String str, Integer num) {
        return new Pair<>(str, num);
    }

    private List<String> generate_neighbours(String str) {
        List<String> neighbours = new ArrayList<>();
        char[] chars = str.toCharArray();

        for(int i=0; i<4; i++) {
            char orgChar = chars[i];
            chars[i] = (orgChar == '0') ? '9' : (char)(orgChar - 1);
            neighbours.add(new String(chars));

            chars[i] = (orgChar == '9') ? '0' : (char)(orgChar + 1);
            neighbours.add(new String(chars));

            chars[i] = orgChar;
        }

        return neighbours;
    }
}
