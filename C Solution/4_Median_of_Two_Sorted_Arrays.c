// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, k = 0;
    int *nums3 = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            nums3[k++] = nums1[i++];
        } else {
            nums3[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        nums3[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        nums3[k++] = nums2[j++];
    }
    double median = 0;
    if ((nums1Size + nums2Size) % 2 == 0) {
        median = (nums3[(nums1Size + nums2Size) / 2] + nums3[(nums1Size + nums2Size) / 2 - 1]) / 2.0;
    } else {
        median = nums3[(nums1Size + nums2Size) / 2];
    }
    free(nums3);
    return median;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    printf("%f", findMedianSortedArrays(nums1, sizeof(nums1) / sizeof(int), nums2, sizeof(nums2) / sizeof(int)));
    return 0;
}