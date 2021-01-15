// Given an input string (s) and a pattern (p), implement wildcard pattern
// matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not
// match 'b'.

// Example 4:
// Input: s = "adceb", p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*'
// matches the substring "dce".

// Example 5:
// Input: s = "acdcb", p = "a*c?b"
// Output: false

// Constraints:
// 0 <= s.length, p.length <= 2000
// s contains only lowercase English letters.
// p contains only lowercase English letters, '?' or '*'.

#include <string>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    if (s.size() == 0) {
      for (int i = 0; i < p.size(); i++) {
        if (p[i] != '*') {
          return false;
        }
      }
      return true;
    }
    if (p.size() == 0) {
      return false;
    }

    bool table[s.size()][p.size()];
    memset(table, false, sizeof(table));
    if (p[0] == '*') {
      for (int i = 0; i < s.size(); i++) {
        table[i][0] = true;
      }
      int j = 1;
      while (j < p.size() && p[j] == '*') {
        table[0][j] = true;
        j++;
      }
      if (j < p.size() && (p[j] == '?' || p[j] == s[0])) {
        table[0][j] = true;
        j++;
      }
      while (j < p.size() && p[j] == '*') {
        table[0][j] = true;
        j++;
      }
    } else if (s[0] == p[0] || p[0] == '?') {
      table[0][0] = true;
      int j = 1;
      while (j < p.size() && p[j] == '*') {
        table[0][j] = true;
        j++;
      }
    }

    for (int i = 1; i < s.size(); i++) {
      for (int j = 1; j < p.size(); j++) {
        if (table[i - 1][j - 1] &&
            (s[i] == p[j] || p[j] == '*' || p[j] == '?')) {
          table[i][j] = true;
        } else if (table[i - 1][j] && p[j] == '*') {
          table[i][j] = true;
        } else if (table[i][j - 1] && p[j] == '*') {
          table[i][j] = true;
        }
      }
    }

    return table[s.size() - 1][p.size() - 1];
  }
};