// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order. An Anagram is a word or phrase formed by rearranging
// the letters of a different word or phrase, typically using all the original
// letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:
// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> umap;
    vector<vector<string>> result;
    int counter = 0;
    for (int i = 0; i < strs.size(); i++) {
      string curStr = strs[i];
      sort(curStr.begin(), curStr.end());
      auto it = umap.find(curStr);
      if (it == umap.end()) {
        umap.insert({curStr, counter});
        result.push_back({strs[i]});
        counter++;
      } else {
        result[it->second].push_back(strs[i]);
      }
    }
    return result;
  }
};