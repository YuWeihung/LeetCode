/*
 * @lc app=leetcode.cn id=2176 lang=cpp
 *
 * [2176] 统计数组中相等且可以被整除的数对
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
const int MX = 101;
vector<int> divisors[MX];

auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
public:
    int countPairs(vector<int> &nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int j = 0; j < nums.size();
             j++) { // 枚举 j，计算左边有多少个符合要求的 i
            int x = nums[j];
            if (j && x == nums[0]) {
                ans++; // 单独统计 i=0 的情况
            }
            int k2 = k / gcd(k, j); // i 必须是 k2 的倍数
            ans += cnt[k2 << 10 |
                       x]; // 用位运算把二元组 (x, k2) 合并成一个整数
            for (int d : divisors[j]) { // j 是 d 的倍数
                cnt[d << 10 | x]++;
            }
        }
        return ans;
    }
};
// @lc code=end
