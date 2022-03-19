// Given a string s, find the length of the longest substring without repeating
// characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.

// Example 4:
// Input: s = ""
// Output: 0

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if (size == 0) return 0;
        unordered_map<char, int> hashMap;
        int maxLength = 1;
        int rightIdx = 0;
        int leftIdx = 0;
        while (rightIdx < size) {
            auto search = hashMap.find(s[rightIdx]);
            if (search != hashMap.end()) {
                maxLength = (rightIdx - leftIdx) > maxLength ? 
                    rightIdx - leftIdx : maxLength;
                leftIdx = search->second + 1 > leftIdx ? 
                    search->second + 1 : leftIdx;
                search->second = rightIdx;
            } else {
                hashMap.insert({s[rightIdx], rightIdx});
            }
            ++rightIdx;
        }
        maxLength = (rightIdx - leftIdx) > maxLength ? rightIdx - leftIdx : maxLength;
        return maxLength;
    }
};