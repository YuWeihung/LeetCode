/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1;
        int j = b.size() - 1;
        // carry 为进位标志位
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int sum = carry;
            sum += a[i] - '0';
            sum += b[j] - '0';
            carry = sum / 2;
            ans.push_back((sum % 2) + '0');
            i--;
            j--;
        }
        // 如果 a 没遍历完成，继续遍历 a 剩余部分，b 同理
        while (i >= 0) {
            int sum = carry;
            sum += a[i] - '0';
            carry = sum / 2;
            ans.push_back((sum % 2) + '0');
            i--;
        }
        while (j >= 0) {
            int sum = carry;
            sum += b[j] - '0';
            carry = sum / 2;
            ans.push_back((sum % 2) + '0');
            j--;
        }
        // 最高位有进位
        if (carry > 0) {
            ans.push_back(carry + '0');
        }
        // 翻转字符串，定义在 algorithm 库中
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
