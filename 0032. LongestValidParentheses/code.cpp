// Given a string containing just the characters '(' and ')', find the length of
// the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".

// Example 2:
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

// Example 3:
// Input: s = ""
// Output: 0

// Constraints:
// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> todo;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        todo.push(i);
      } else if (s[i] == ')') {
        if (todo.size() && s[todo.top()] == '(') {
          todo.pop();
        } else {
          todo.push(i);
        }
      }
    }

    if (todo.empty()) return s.size();
    int start;
    int end = s.size();
    int maxLength = 0;
    while (!todo.empty()) {
      start = todo.top();
      todo.pop();
      maxLength = (end - start - 1 > maxLength) ? end - start - 1 : maxLength;
      end = start;
    }
    maxLength = (end - (-1) - 1 > maxLength) ? end : maxLength;

    return maxLength;
  }
};