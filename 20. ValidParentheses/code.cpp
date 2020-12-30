// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid. An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "([)]"
// Output: false

// Example 5:
// Input: s = "{[]}"
// Output: true

// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    char open[] = {'(', '{', '['};
    char close[] = {')', '}', ']'};
    stack<char> paren;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        paren.push(s[i]);
      } else if (s[i] == ')') {
        if (!paren.empty() && paren.top() == '(') {
          paren.pop();
        } else {
          return false;
        }
      } else if (s[i] == '}') {
        if (!paren.empty() && paren.top() == '{') {
          paren.pop();
        } else {
          return false;
        }
      } else if (s[i] == ']') {
        if (!paren.empty() && paren.top() == '[') {
          paren.pop();
        } else {
          return false;
        }
      }
    }

    if (!paren.empty()) {
      return false;
    }
    return true;
  }
};