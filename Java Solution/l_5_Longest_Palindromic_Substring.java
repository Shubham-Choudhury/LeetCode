// Link: https://leetcode.com/problems/longest-palindromic-substring/

public class l_5_Longest_Palindromic_Substring {
    public String longestPalindrome(String s) {
        int size = s.length();
        if (size == 0)
            return "";
        if (size == 1)
            return s;

        int MAX = 1;
        int start = 0;
        int end = 0;

        for (int i = 0; i < size; i++) {
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k < size && s.charAt(j) == s.charAt(k)) {
                j--;
                k++;
            }
            if (k - j - 1 > MAX) {
                MAX = k - j - 1;
                start = j + 1;
                end = k - 1;
            }
            j = i;
            k = i + 1;
            while (j >= 0 && k < size && s.charAt(j) == s.charAt(k)) {
                j--;
                k++;
            }
            if (k - j - 1 > MAX) {
                MAX = k - j - 1;
                start = j + 1;
                end = k - 1;
            }
        }
        return s.substring(start, end + 1);
    }

    public static void main(String[] args) {
        l_5_Longest_Palindromic_Substring solution = new l_5_Longest_Palindromic_Substring();
        String s = "babad";
        System.out.println(solution.longestPalindrome(s));
    }
}
