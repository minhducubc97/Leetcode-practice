// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the
// following sequence for n = 3: "123" "132" "213" "231" "312" "321" Given n and
// k, return the kth permutation sequence.

// Example 1:
// Input: n = 3, k = 3
// Output: "213"

// Example 2:
// Input: n = 4, k = 9
// Output: "2314"

// Example 3:
// Input: n = 3, k = 1
// Output: "123"

// Constraints:
// 1 <= n <= 9
// 1 <= k <= n!

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    vector<bool> visited(n, false);
    string curP = "";
    int count = 0;
    string result = "";
    getPermutation(visited, curP, count, k, result);
    return result;
  }

  bool getPermutation(vector<bool>& visited, string curP, int& count, int k,
                      string& result) {
    int n = visited.size();
    if (curP.size() == n) {
      ++count;
      if (count == k) {
        result = curP;
        return true;
      }
    }
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      visited[i] = true;
      if (getPermutation(visited, curP + to_string(i + 1), count, k, result))
        return true;
      visited[i] = false;
    }
    return false;
  }
};