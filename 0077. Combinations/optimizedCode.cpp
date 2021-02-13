#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> curCom;
    combineSub(result, curCom, k, n, 1);
    return result;
  }

  void combineSub(vector<vector<int>>& result, vector<int>& curCom, int k,
                  int n, int idx) {
    if (curCom.size() == k) {
      result.push_back(curCom);
      return;
    }
    for (int i = idx; i <= n; i++) {
      curCom.push_back(i);
      combineSub(result, curCom, k, n, i + 1);
      curCom.pop_back();
    }
  }
};