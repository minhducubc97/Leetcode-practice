// Given a 32-bit signed integer, reverse digits of an integer.
// Note:
// Assume we are dealing with an environment that could only store integers
// within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
// this problem, assume that your function returns 0 when the reversed integer
// overflows.

// Example 1:
// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
// Example 4:

// Input: x = 0
// Output: 0

// Constraints:
// -231 <= x <= 231 - 1

#include <limits>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int result = 0;
    while (x != 0) {
      int rem = x % 10;
      x /= 10;
      if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && rem > 7))
        return 0;
      if ((result < INT_MIN / 10) || (result == INT_MIN / 10 && rem < -8))
        return 0;
      result = result * 10 + rem;
    }
    return result;
  }
};