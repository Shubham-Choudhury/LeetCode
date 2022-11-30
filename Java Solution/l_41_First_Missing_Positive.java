// Link: https://leetcode.com/problems/first-missing-positive/

class l_41_First_Missing_Positive {
    public int firstMissingPositive(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            if (nums[i] > 0 && nums[i] <= nums.length && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            } else {
                i++;
            }
        }
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.length + 1;
    }

    public static void main(String[] args) {
        l_41_First_Missing_Positive solution = new l_41_First_Missing_Positive();
        int[] nums = {3, 4, -1, 1};
        System.out.println(solution.firstMissingPositive(nums));
    }
}