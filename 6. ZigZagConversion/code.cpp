// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility) P   A   H   N A P L S I I G Y   I   R And then read line
// by line: "PAHNAPLSIIGYIR" Write the code that will take a string and make
// this conversion given a number of rows: string convert(string s, int
// numRows);

// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"

// Constraints:
// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000

#include <string>
using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }

    int size = s.size();
    string result = "";
    int counter = 0;
    int differenceDown = 2 * (numRows - 1);
    int differenceUp = 0;

    for (int counter = 0; counter < numRows; counter++) {
      int i = counter;
      bool isDown = true;
      bool update = true;
      while (i < size) {
        if (!update) {
          update = true;
        } else {
          result = result + s[i];
        }
        if (isDown) {
          if (counter != numRows - 1) {
            i += differenceDown;
          } else {
            update = false;
          }
          isDown = !isDown;
        } else {
          if (counter != 0) {
            i += differenceUp;
          } else {
            update = false;
          }
          isDown = !isDown;
        }
      }
      differenceDown -= 2;
      differenceUp += 2;
    }

    return result;
  }
};