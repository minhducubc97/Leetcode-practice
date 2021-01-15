#include <string>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.size() == 0) {
      return (s.size() == 0);
    }

    bool table[s.size() + 1][p.size() + 1];
    memset(table, false, sizeof(table));
    table[0][0] = true;

    for (int j = 1; j <= p.size(); j++) {
      if (p[j - 1] == '*') {
        table[0][j] = table[0][j - 1];
      }
    }

    for (int i = 1; i <= s.size(); i++) {
      for (int j = 1; j <= p.size(); j++) {
        if (p[j - 1] == '*') {
          table[i][j] = table[i][j - 1] || table[i - 1][j];
        } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
          table[i][j] = table[i - 1][j - 1];
        }
      }
    }

    return table[s.size()][p.size()];
  }
};