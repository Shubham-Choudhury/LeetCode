// Link: https://leetcode.com/problems/first-missing-positive/

var firstMissingPositive = function(nums) {
    let i = 0;
    while (i < nums.length) {
        if (nums[i] > 0 && nums[i] <= nums.length && nums[i] !== nums[nums[i] - 1]) {
            let temp = nums[i];
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
        } else {
            i++;
        }
    }
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== i + 1) {
            return i + 1;
        }
    }
    return nums.length + 1;
};

console.log(firstMissingPositive([1,2,0]));