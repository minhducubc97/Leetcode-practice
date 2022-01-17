using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string s1Temp = s1, s2Temp = s2;
        sort(s1Temp.begin(), s1Temp.end());
        sort(s2Temp.begin(), s2Temp.end());
        if (s1Temp != s2Temp) return false;
        int size = s1Temp.size();
        for (int i = 1; i < size; i++) {
            string s1Left = s1.substr(0, i);
            string s1Right = s1.substr(i);
            string s2Left = s2.substr(0, i);
            string s2Right = s2.substr(i);
            if (isScramble(s1Left, s2Left) && isScramble(s1Right, s2Right)) return true;
            string s2Left2 = s2.substr(0, size - i);
            string s2Right2 = s2.substr(size - i);
            if (isScramble(s1Left, s2Right2) && isScramble(s1Right, s2Left2)) return true;
        }
        return false;
    }
};