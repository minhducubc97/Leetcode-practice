class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums[0] >= 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = pow(nums[i], 2);
            }
            return nums;
        }
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;
        vector<int> result = {};
        while (leftIdx <= rightIdx) {
            if (abs(nums[leftIdx]) < abs(nums[rightIdx])) {
                result.push_back(pow(nums[rightIdx], 2));
                --rightIdx;
            } else {
                result.push_back(pow(nums[leftIdx], 2));
                ++leftIdx;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};