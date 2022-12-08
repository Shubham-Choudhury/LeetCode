// Link: https://leetcode.com/problems/integer-to-roman/

public class l_12_Integer_to_Roman {
    public String intToRoman(int num) {
        int[] values = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        String[] romanLetters = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        String roman = new String();
        for (int i = 0; i < values.length; i++) {
            while (num >= values[i]) {
                num = num - values[i];

                roman = roman + romanLetters[i];
            }
        }

        return roman;
    }

    public static void main(String[] args) {
        l_12_Integer_to_Roman solution = new l_12_Integer_to_Roman();
        int num = 1994;
        System.out.println(solution.intToRoman(num));
    }
}
