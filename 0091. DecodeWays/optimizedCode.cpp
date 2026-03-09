class Solution {
public:
    int numDecodings(string s) {
      vector<int> memo(s.size() + 1, 0);
      return helper(s, s.size(), memo);
    }

    int helper(string s, int length, vector<int>& memo) {
        if (length == 0) return 1;
        int startIdx = s.size() - length;
        if (s[startIdx] == '0') return 0;
        
        if (memo[length] != 0) return memo[length];
        
        int result = helper(s, length - 1, memo);
        if (length >= 2 && (s[startIdx] == '1' || (s[startIdx] == '2' && s[startIdx + 1] <= '6'))) {
            result += helper(s, length - 2, memo);
        }
        memo[length] = result;
        
        return result;
    }
};