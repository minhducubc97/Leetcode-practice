// You are given a string s and an array of strings words of the same length.
// Return all starting indices of substring(s) in s that is a concatenation of
// each word in words exactly once, in any order, and without any intervening
// characters. You can return the answer in any order.

// Example 1:
// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
// respectively. The output order does not matter, returning [9,0] is fine too.

// Example 2:
// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []

// Example 3:
// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]

// Constraints:
// 1 <= s.length <= 104
// s consists of lower-case English letters.
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// words[i] consists of lower-case English letters.

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int charInWords = words.size() * words[0].size();
    vector<int> result;
    if (charInWords > s.size()) return result;

    unordered_map<string, int> umap;
    for (int i = 0; i < words.size(); i++) {
      umap[words[i]]++;
    }

    bool wrongIndex;
    for (int i = 0; i <= s.size() - charInWords; i++) {
      wrongIndex = false;
      unordered_map<string, int> toCheck(umap);
      for (int j = i; j < charInWords + i; j += words[0].size()) {
        string wordToFind = s.substr(j, words[0].size());
        if (toCheck.find(wordToFind) == toCheck.end() ||
            toCheck[wordToFind] == 0) {
          wrongIndex = true;
          break;
        } else {
          toCheck[wordToFind]--;
        }
      }

      if (!wrongIndex) {
        result.push_back(i);
      }
    }

    return result;
  }
};