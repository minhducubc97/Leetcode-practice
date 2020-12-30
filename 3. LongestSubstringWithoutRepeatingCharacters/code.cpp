// Given a string s, find the length of the longest substring without repeating
// characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.

// Example 4:
// Input: s = ""
// Output: 0

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hashMap;
    int maxSize = 0;
    int currSize = 0;
    int lastDuplicateIndex = 0;
    for (int i = 0; i < s.size(); i++) {
      auto search = hashMap.find(s[i]);
      if (search == hashMap.end()) {
        hashMap.insert(pair<char, int>(s[i], i));
        currSize++;
      } else {
        maxSize = (currSize > maxSize) ? currSize : maxSize;
        lastDuplicateIndex = (lastDuplicateIndex > search->second)
                                 ? lastDuplicateIndex
                                 : search->second;
        currSize = i - lastDuplicateIndex;
        search->second = i;
      }
    }
    maxSize = (currSize > maxSize) ? currSize : maxSize;
    return maxSize;
  }
};