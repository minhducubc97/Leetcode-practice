// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
// An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true

// Example 2:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

// Example 3:
// Input: s1 = "", s2 = "", s3 = ""
// Output: true
 
// Constraints:
// 0 <= s1.length, s2.length <= 100
// 0 <= s3.length <= 200
// s1, s2, and s3 consist of lowercase English letters.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {        
        int s1Size = s1.size();
        int s2Size = s2.size();
        int s3Size = s3.size();
        if (s1Size + s2Size != s3Size) return false;
        vector<vector<bool>> dp(s1Size + 1, vector<bool>(s2Size + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s1Size; i++) {
            if (s1[i - 1] == s3[i - 1] && dp[i - 1][0]) dp[i][0] = true;
            else dp[i][0] = false;
        }
        for (int j = 1; j <= s2Size; j++) {
            if (s2[j - 1] == s3[j - 1] && dp[0][j - 1]) dp[0][j] = true;
            else dp[0][j] = false;
        }
        for (int i = 1; i <= s1Size; i++) {
            for (int j = 1; j <= s2Size; j++) {
                if (dp[i][j - 1] == true) {
                    dp[i][j] = (s3[i + j - 1] == s2[j - 1]);
                } else if (dp[i - 1][j] == true) {
                    dp[i][j] = (s3[i + j - 1] == s1[i - 1]);
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[s1Size][s2Size];
    }
};