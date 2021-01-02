// Write a function to find the longest common prefix string amongst an array of
// strings. If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:
// 0 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    int firstWordLength = strs[0].size();
    string result = "";
    for (int charIdx = 0; charIdx < firstWordLength; charIdx++) {
      char letterToCompare = strs[0][charIdx];
      for (int strIdx = 0; strIdx < strs.size(); strIdx++) {
        if (strs[strIdx].size() == charIdx ||
            strs[strIdx][charIdx] != letterToCompare) {
          cout << result;
          return result;
        }
      }
      result += letterToCompare;
    }
    return result;
  }
};