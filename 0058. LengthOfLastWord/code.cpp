// Given a string s consists of some words separated by spaces, return the
// length of the last word in the string. If the last word does not exist,
// return 0. A word is a maximal substring consisting of non-space characters
// only.

// Example 1:
// Input: s = "Hello World"
// Output: 5

// Example 2:
// Input: s = " "
// Output: 0

// Constraints:
// 1 <= s.length <= 104
// s consists of only English letters and spaces ' '.

#include <string>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int lastWordLength = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i > 0 && s[i - 1] == ' ' && s[i] != ' ')
        lastWordLength = 1;
      else if (s[i] != ' ')
        lastWordLength++;
    }
    return lastWordLength;
  }
};