// Link: https://leetcode.com/problems/palindrome-number/

public class l_9_Palindrome_Number {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        int y = x;
        int z = 0;
        while (y != 0) {
            z = z * 10 + y % 10;
            y /= 10;
        }
        return z == x;
    }

    public static void main(String[] args) {
        l_9_Palindrome_Number solution = new l_9_Palindrome_Number();
        int x = 121;
        System.out.println(solution.isPalindrome(x));
    }
}
