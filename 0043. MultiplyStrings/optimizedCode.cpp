#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int resultSize = num1.size() + num2.size();
    vector<int> rawResult(resultSize, 0);
    for (int i = 0; i < num1.size(); i++) {
      for (int j = 0; j < num2.size(); j++) {
        rawResult[i + j] += (num1[i] - '0') * (num2[j] - '0');
      }
    }

    int digit;
    int carry = 0;
    string result = "";
    for (int i = 0; i < resultSize; i++) {
      digit = (rawResult[i] + carry) % 10;
      carry = (rawResult[i] + carry) / 10;
      result = to_string(digit) + result;
    }

    return (result[0] == '0') ? result.substr(1) : result;
  }
};