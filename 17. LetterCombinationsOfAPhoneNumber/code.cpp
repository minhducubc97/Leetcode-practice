// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order. A mapping of digit to letters (just like on the telephone buttons) is
// given below. Note that 1 does not map to any letters.

// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = ""
// Output: []

// Example 3:
// Input: digits = "2"
// Output: ["a","b","c"]

// Constraints:
// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.size() == 0) {
      return result;
    }
    unordered_map<char, string> umap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> digitsConv;
    for (int i = 0; i < digits.size(); i++) {
      auto it = umap.find(digits[i]);
      if (it == umap.end())
        continue;
      else {
        digitsConv.push_back(it->second);
      }
    }

    queue<string> q;
    q.push("");
    while (!q.empty()) {
      string top = q.front();
      q.pop();

      if (top.size() == digits.size()) {
        result.push_back(top);
      } else {
        for (auto it : digitsConv[top.size()]) {
          q.push(top + it);
        }
      }
    }

    return result;
  }
};