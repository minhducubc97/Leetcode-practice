class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (target <= nums[0]) return 0;
        if (target > nums[right]) return right + 1;
        while (left < right) {
            if (right == left + 1) return right;
            int middle = (right - left) / 2 + left;
            if (nums[middle] == target) return middle;
            if (nums[middle] > target) right = middle;
            else left = middle;
        }
        return left;
    }
};