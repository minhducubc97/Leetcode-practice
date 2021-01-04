// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.

// Clarification:
// What should we return when needle is an empty string? This is a great
// question to ask during an interview. For the purpose of this problem, we will
// return 0 when needle is an empty string. This is consistent to C's strstr()
// and Java's indexOf().

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Example 3:
// Input: haystack = "", needle = ""
// Output: 0

// Constraints:
// 0 <= haystack.length, needle.length <= 5 * 104
// haystack and needle consist of only lower-case English characters.

#include <string>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    if (haystack.size() < needle.size()) return -1;
    int haystackIdx = 0;
    int needleIdx = 0;
    int foundIdx = -1;
    while (haystackIdx < haystack.size()) {
      if (haystack[haystackIdx] == needle[needleIdx]) {
        foundIdx = haystackIdx;
        while (haystackIdx < haystack.size() && needleIdx < needle.size() &&
               haystack[haystackIdx] == needle[needleIdx]) {
          haystackIdx++;
          needleIdx++;
        }
        if (needleIdx < needle.size()) {
          needleIdx = 0;
          haystackIdx = foundIdx + 1;
          foundIdx = -1;
        }
      } else {
        haystackIdx++;
      }
      if (needleIdx == needle.size() ||
          (haystack.size() - haystackIdx < needle.size())) {
        break;
      }
    }
    return foundIdx;
  }
};