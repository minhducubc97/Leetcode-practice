// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

// Example 1:
// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Example 2:
// Input: s = "3z4"
// Output: ["3z4","3Z4"]

// Constraints:
// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string curStr = "";
        letterCasePermutationHelper(result, s, curStr, 0);
        return result;
    }
    
    void letterCasePermutationHelper(vector<string>& result, string s, string curStr, int curIdx) {
        int size = s.size();
        if (curIdx == size) result.push_back(curStr);
        else {
            curStr.push_back(s[curIdx]);
            letterCasePermutationHelper(result, s, curStr, curIdx + 1);
            if (!isdigit(s[curIdx])) {
                curStr.pop_back();
                if (isupper(s[curIdx])) {
                    curStr.push_back(tolower(s[curIdx]));
                    letterCasePermutationHelper(result, s, curStr, curIdx + 1);
                } else {
                    curStr.push_back(toupper(s[curIdx]));
                    letterCasePermutationHelper(result, s, curStr, curIdx + 1);
                }
            } 
        }
    }
};