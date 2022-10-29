// Link: https://leetcode.com/problems/merge-sorted-array/?envType=study-plan&id=data-structure-i

public class l_88_Merge_Sorted_Array {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int index = m + n - 1;
        int index1 = m - 1;
        int index2 = n - 1;
        while (index1 >= 0 && index2 >= 0) {
            if (nums1[index1] > nums2[index2]) {
                nums1[index] = nums1[index1];
                index1--;
            } else {
                nums1[index] = nums2[index2];
                index2--;
            }
            index--;
        }
        while (index2 >= 0) {
            nums1[index] = nums2[index2];
            index2--;
            index--;
        }
    }

    public static void main(String[] args) {
        l_88_Merge_Sorted_Array solution = new l_88_Merge_Sorted_Array();
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        solution.merge(nums1, 3, nums2, 3);
        for (int i = 0; i < nums1.length; i++) {
            System.out.print(nums1[i] + " ");
        }
    }
    
}
