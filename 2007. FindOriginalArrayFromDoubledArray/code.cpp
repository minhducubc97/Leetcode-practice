// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

// Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

// Example 1:
// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].

// Example 2:
// Input: changed = [6,3,0,1]
// Output: []
// Explanation: changed is not a doubled array.

// Example 3:
// Input: changed = [1]
// Output: []
// Explanation: changed is not a doubled array.

// Constraints:
// 1 <= changed.length <= 105
// 0 <= changed[i] <= 105

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int size = changed.size();
        if (size % 2 != 0) return {};
        sort(changed.begin(), changed.end());
        vector<int> result = {};
        while (size > 0) {
            int firstDoubleIdx = searchDoubleIdx(changed, 1, size - 1, changed[0] * 2);
            if (firstDoubleIdx == -1) return {};
            result.push_back(changed[0]);
            changed.erase(changed.begin() + firstDoubleIdx);
            changed.erase(changed.begin());
            size -= 2;
        }
        return result;
    }
    
    int searchDoubleIdx(vector<int>& changed, int left, int right, int target) {
        if (left >= right) {
            if (changed[left] == target) return left;
            else return -1;
        }
        int middle = (right - left) / 2 + left;
        int leftHalf = searchDoubleIdx(changed, left, middle, target);
        int rightHalf = searchDoubleIdx(changed, middle + 1, right, target);
        return (leftHalf == -1) ? rightHalf : leftHalf;
    }
};