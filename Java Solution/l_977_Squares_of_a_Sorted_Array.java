// Link: https://leetcode.com/problems/squares-of-a-sorted-array/?envType=study-plan&id=algorithm-i

class l_977_Squares_of_a_Sorted_Array {
    public int[] sortedSquares(int[] nums) {
        int[] result = new int[nums.length];
        int left = 0;
        int right = nums.length - 1;
        int index = nums.length - 1;
        while (left <= right) {
            if (Math.abs(nums[left]) > Math.abs(nums[right])) {
                result[index] = nums[left] * nums[left];
                left++;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        return result;
    }

    public static void main(String[] args) {
        l_977_Squares_of_a_Sorted_Array solution = new l_977_Squares_of_a_Sorted_Array();
        int[] nums = {-4, -1, 0, 3, 10};
        int[] result = solution.sortedSquares(nums);
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}