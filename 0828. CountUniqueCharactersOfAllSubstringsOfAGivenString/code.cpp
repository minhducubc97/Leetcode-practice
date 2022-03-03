// Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

// For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
// Given a string s, return the sum of countUniqueChars(t) where t is a substring of s.

// Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

// Example 1:
// Input: s = "ABC"
// Output: 10
// Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
// Evey substring is composed with only unique letters.
// Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

// Example 2:
// Input: s = "ABA"
// Output: 8
// Explanation: The same as example 1, except countUniqueChars("ABA") = 1.

// Example 3:
// Input: s = "LEETCODE"
// Output: 92

// Constraints:
// 1 <= s.length <= 105
// s consists of uppercase English letters only.

class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<char, int> hashMap;
        int leftIdx = 0;
        int length = 1;
        int size = s.size();
        int result  = 0;
        while (leftIdx < size && length <= size) {
            if (hashMap.size() > 0) hashMap.clear();
            result += countUniqueChars(s.substr(leftIdx, length), hashMap);
            leftIdx++;
            if (leftIdx + length == size) {
                length++;
                leftIdx = 0;
            }
        }
        return result;
    }
    
    int countUniqueChars(string s, unordered_map<char, int>& hashMap) {
        if (s.size() == 1) return 1;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            auto search = hashMap.find(s[i]);
            if (search != hashMap.end()) {
                if (search->second == 0) {
                    search->second++;
                    result -= 1;
                }
            } else {
                hashMap.insert(pair<char, int>(s[i], 0));
                result++;
            }
        }
        return result;
    }
};