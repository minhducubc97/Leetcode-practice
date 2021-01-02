// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

// Constraints:
// 1 <= n <= 8

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string emptyStr = "";
    subGenerateParenthesis(n, result, emptyStr, 0, 0, 0);
    return result;
  }

  void subGenerateParenthesis(int n, vector<string>& result, string curStr,
                              int curPos, int leftBracket, int rightBracket) {
    if (curPos == 2 * n) {
      result.push_back(curStr);
    }
    if (leftBracket < n) {
      string curStrCopy = curStr + "(";
      subGenerateParenthesis(n, result, curStrCopy, curPos + 1, leftBracket + 1,
                             rightBracket);
    }
    if (rightBracket < leftBracket) {
      string curStrCopy = curStr + ")";
      subGenerateParenthesis(n, result, curStrCopy, curPos + 1, leftBracket,
                             rightBracket + 1);
    }
  }
};