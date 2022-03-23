// Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.

// Example 1:
// Input: s = "owoztneoer"
// Output: "012"

// Example 2:
// Input: s = "fviefuro"
// Output: "45"

// Constraints:
// 1 <= s.length <= 105
// s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
// s is guaranteed to be valid.

class Solution {
public:
    string originalDigits(string s) {
        vector<int> mp(26, 0), nums(10, 0);
        for (char c:s) mp[c-'a']++;
        nums[0] = mp['z'-'a'];
        nums[2] = mp['w'-'a'];
        nums[4] = mp['u'-'a'];
        nums[1] = mp['o'-'a']-nums[0]-nums[2]-nums[4];
        nums[3] = mp['r'-'a']-nums[0]-nums[4];
        nums[6] = mp['x'-'a'];
        nums[7] = mp['s'-'a']-nums[6];
        nums[8] = mp['g'-'a'];
        nums[5] = mp['v'-'a']-nums[7];
        nums[9] = mp['i'-'a']-nums[5]-nums[6]-nums[8];
        string ans;
        for (int i = 0; i < 10; i++) {
            ans += string(nums[i], '0' + i);
        }
        return ans;
    }
};