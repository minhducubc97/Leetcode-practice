using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) return 0;
        return floor(sqrt(n+0.125)*sqrt(2) - 0.5);
    }
};