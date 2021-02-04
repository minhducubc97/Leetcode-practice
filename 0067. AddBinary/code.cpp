// Given two binary strings a and b, return their sum as a binary string.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

// Constraints:
// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#include <string>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int m = a.size(), n = b.size(), tmpSum = 0, remainder = 0;
    string result = "";
    string s(abs(m - n), '0');
    if (m > n)
      b = s + b;
    else if (n > m)
      a = s + a;
    for (int i = a.size() - 1; i >= 0; i--) {
      tmpSum = ((a[i] - '0') ^ (b[i] - '0')) ^ remainder;
      remainder = ((a[i] - '0') && (b[i] - '0')) ||
                  ((a[i] - '0') && remainder) || ((b[i] - '0') && remainder);
      result = to_string(tmpSum) + result;
    }
    if (remainder) result = '1' + result;
    return result;
  }
};