class Solution {
public:
    int uniqueLetterString(string s) {
        int result = 0;
        int rightIdx = 0;
        int leftIdx = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            rightIdx = i + 1;
            leftIdx = i - 1;
            while (leftIdx >= 0 && s[leftIdx] != s[i]) {
                leftIdx--;
            }
            while (rightIdx < size && s[rightIdx] != s[i]) {
                rightIdx++;
            }
            result += (i - leftIdx) * (rightIdx - i);
        }
        return result;
    }
};