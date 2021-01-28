#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    string result;
    string num = "123456789";
    vector<int> factorial(n, 1);
    for (int i = 1; i < n; ++i) factorial[i] = factorial[i - 1] * i;
    --k;
    for (int i = n; i >= 1; i--) {
      int digitIdx = k / factorial[i - 1];
      k %= factorial[i - 1];
      result.push_back(num[digitIdx]);
      num.erase(digitIdx, 1);
    }
    return result;
  }
};