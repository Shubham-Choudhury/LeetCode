// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/


public class l_3_Longest_Substring_Without_Repeating_Characters {
    public int lengthOfLongestSubstring(String s) {
        int size = s.length();
        if (size == 0)
            return 0;

        int MAX = 1;

        int i, j;
        for (i = 0, j = 0; i < size; i++) {
            int pre = s.substring(i - j, i).indexOf(s.charAt(i));
            if (pre != -1)
                MAX = Math.max(j, MAX);
            j = j - pre;
        }
        MAX = Math.max(j, MAX);
        return MAX;
    }

    public static void main(String[] args) {
        l_3_Longest_Substring_Without_Repeating_Characters solution = new l_3_Longest_Substring_Without_Repeating_Characters();
        String s = "abcabcbb";
        System.out.println(solution.lengthOfLongestSubstring(s));
    }
}
