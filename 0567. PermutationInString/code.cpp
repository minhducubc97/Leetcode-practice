// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 
// Constraints:
// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.size();
        int size = s2.size();
        if (windowSize > size) return false;
        unordered_map< char, int >mp;
        for(auto it : s1) mp[it]++;
        int remainingCount = mp.size();
        int i = 0, j = 0;
        while(j < size){
            if(mp.find(s2[j]) != mp.end()) {
                --mp[s2[j]];
                if (mp[s2[j]] == 0) --remainingCount;
            }
            if(j-i+1 < windowSize) j++;
            else if(j-i+1 == windowSize){
				if(remainingCount == 0) return true;  
                if(mp.find(s2[i]) != mp.end()) {
                    ++mp[s2[i]];
                    if (mp[s2[i]] == 1) ++remainingCount;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};