// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

// Given the integer n, return the number of complete rows of the staircase you will build.

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int curRowCoinCount = 1;
        int result = 0;
        while (n >= curRowCoinCount) {
            n -= curRowCoinCount;
            curRowCoinCount++;
            result++;
        }
        return result;
    }
};