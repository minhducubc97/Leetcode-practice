// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

// Example 1:
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]

// Example 2:
// Input: s = "0000"
// Output: ["0.0.0.0"]

// Example 3:
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
// Constraints:
// 1 <= s.length <= 20
// s consists of digits only.

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result = {};
        string curIp = "";
        restoreIpAddressesHelper(result, curIp, s, 0);
        return result;
    }
    
    void restoreIpAddressesHelper(vector<string>& result, string curIp, string remaining, int counter) {
        int size = remaining.size();
        if (counter == 4 && size == 0) {
            result.push_back(curIp);
        }
        else if (counter < 4 && size >= 1) {
            string separator = (counter == 3) ? "" : ".";
            restoreIpAddressesHelper(result, curIp + remaining.substr(0,1) + separator, remaining.substr(1, size - 1), counter + 1);
            if (remaining.substr(0,1) != "0" && size >= 2) {
                restoreIpAddressesHelper(result, curIp + remaining.substr(0,2) + separator, remaining.substr(2, size - 2), counter + 1);
                if (stoi(remaining.substr(0,3)) <= 255 && size >=3) {
                    restoreIpAddressesHelper(result, curIp + remaining.substr(0,3) + separator, remaining.substr(3, size - 3), counter + 1);
                }
            }
        }
    }
};