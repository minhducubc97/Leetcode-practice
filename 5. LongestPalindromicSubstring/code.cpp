// Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Example 3:
// Input: s = "a"
// Output: "a"

// Example 4:
// Input: s = "ac"
// Output: "a"

// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case),

#include <string>

class Solution {
 public:
  string longestPalindrome(string s) {
    int size = s.size();

    if (size == 0) {
      return "";
    }

    bool table[size][size];

    memset(table, 0, sizeof(table));

    int longestLength = 1;
    int startingIndex = 0;

    // subtring length = 1
    for (int i = 0; i < size; i++) {
      table[i][i] = true;
    }

    // subtring length = 2
    for (int j = 0; j < size - 1; j++) {
      if (s.at(j) == s.at(j + 1)) {
        table[j][j + 1] = true;
        startingIndex = j;
        longestLength = 2;
      }
    }

    // substring length >= 3
    for (int length = 3; length <= size; length++) {
      for (int x = 0; x <= size - length; x++) {
        int y = x + length - 1;
        if (table[x + 1][y - 1] && (s.at(x) == s.at(y))) {
          table[x][y] = true;
          startingIndex = x;
          longestLength = length;
        }
      }
    }

    return s.substr(startingIndex, longestLength);
  }
};