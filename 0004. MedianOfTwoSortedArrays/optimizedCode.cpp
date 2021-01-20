#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArraysSub(nums2, nums1);
    } else {
      return findMedianSortedArraysSub(nums1, nums2);
    }
  }

  double findMedianSortedArraysSub(vector<int>& smaller, vector<int>& bigger) {
    int minRange = 0;
    int maxRange = smaller.size();
    int halfLen = (bigger.size() + smaller.size() + 1) / 2;
    while (minRange <= maxRange) {
      int i = (minRange + maxRange) / 2;
      int j = halfLen - i;
      if (i > minRange && smaller[i - 1] > bigger[j]) {
        maxRange--;
      } else if (i < maxRange && bigger[j - 1] > smaller[i]) {
        minRange++;
      } else {
        double maxLeftGroup;
        double minRightGroup;
        if (i == 0)
          maxLeftGroup = bigger[j - 1];
        else if (j == 0)
          maxLeftGroup = smaller[i - 1];
        else
          maxLeftGroup = max(smaller[i - 1], bigger[j - 1]);
        if ((bigger.size() + smaller.size()) % 2 == 1) {
          return maxLeftGroup;
        }

        if (i == smaller.size())
          minRightGroup = bigger[j];
        else if (j == bigger.size())
          minRightGroup = smaller[i];
        else
          minRightGroup = min(smaller[i], bigger[j]);
        return (maxLeftGroup + minRightGroup) / 2;
      }
    }

    return 0.0;
  }
};