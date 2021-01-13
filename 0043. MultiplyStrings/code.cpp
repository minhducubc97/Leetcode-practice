// Given two non-negative integers num1 and num2 represented as strings, return
// the product of num1 and num2, also represented as a string. Note: You must
// not use any built-in BigInteger library or convert the inputs to integer
// directly.

// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"

// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"

// Constraints:
// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0
// itself.

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<string> toAdd;
    for (int i = num2.size() - 1; i >= 0; i--) {
      string curVal = "";
      int digit1;
      int digit2;
      int digitResult;
      int valToRemember = 0;
      for (int j = num1.size() - 1; j > 0; j--) {
        digit2 = num2[i] - '0';
        digit1 = num1[j] - '0';
        digitResult = (digit1 * digit2 + valToRemember) % 10;
        curVal = to_string(digitResult) + curVal;
        valToRemember = (digit1 * digit2 + valToRemember) / 10;
      }
      digit2 = num2[i] - '0';
      digit1 = num1[0] - '0';
      digitResult = digit1 * digit2 + valToRemember;
      curVal = to_string(digitResult) + curVal;

      int counter = num2.size() - 1 - i;
      while (counter) {
        curVal = curVal + "0";
        counter--;
      }
      toAdd.push_back(curVal);
    }
    if (toAdd.size() == 1) return toAdd[0];

    string curVal = "0";
    for (int i = 0; i < toAdd.size(); i++) {
      int digit1;
      int digit2;
      int digitResult;
      int valToRemember = 0;
      int size = toAdd[i].size();
      int sizeOffset = toAdd[i].size() - curVal.size();
      string result = "";
      for (int k = 0; k < sizeOffset; k++) {
        curVal = "0" + curVal;
      }
      for (int j = size - 1; j >= 0; j--) {
        digit1 = toAdd[i][j] - '0';
        digit2 = curVal[j] - '0';
        digitResult = (digit1 + digit2 + valToRemember) % 10;
        result = to_string(digitResult) + result;
        valToRemember = (digit1 + digit2 + valToRemember) / 10;
      }
      if (valToRemember != 0) {
        result = to_string(valToRemember) + result;
      }
      curVal = result;
    }

    return curVal;
  }
};