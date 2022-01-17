// We can scramble a string s to get a string t using the following algorithm:
// If the length of the string is 1, stop.
// If the length of the string is > 1, do the following:
// Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
// Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
// Apply step 1 recursively on each of the two substrings x and y.
// Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.

// Example 1:
// Input: s1 = "great", s2 = "rgeat"
// Output: true
// Explanation: One possible scenario applied on s1 is:
// "great" --> "gr/eat" // divide at random index.
// "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
// "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
// "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
// "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
// "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
// The algorithm stops now and the result string is "rgeat" which is s2.
// As there is one possible scenario that led s1 to be scrambled to s2, we return true.

// Example 2:
// Input: s1 = "abcde", s2 = "caebd"
// Output: false

// Example 3:
// Input: s1 = "a", s2 = "a"
// Output: true

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