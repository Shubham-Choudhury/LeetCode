// Link: https://leetcode.com/problems/container-with-most-water/

public class l_11_Container_With_Most_Water {
    public int maxArea(int[] height) {
        int size = height.length;
        if (size == 0)
            return 0;
        if (size == 1)
            return height[0];

        int MAX = 0;
        int i = 0;
        int j = size - 1;
        while (i < j) {
            MAX = Math.max(MAX, (j - i) * Math.min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return MAX;
    }

    public static void main(String[] args) {
        l_11_Container_With_Most_Water solution = new l_11_Container_With_Most_Water();
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println(solution.maxArea(height));
    }

}
