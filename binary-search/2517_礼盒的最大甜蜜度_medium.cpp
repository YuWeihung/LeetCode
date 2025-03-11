/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int check(vector<int> &price, int k, int ans) {
        int cnt = 1, pre = price[0];
        for (int i = 1; i < price.size(); i++) {
            if (price[i] >= pre + ans) {
                cnt++;
                pre = price[i];
            }
        }
        if (cnt >= k) {
            return true;
        } else {
            return false;
        }
    }

    int maximumTastiness(vector<int> &price, int k) {
        sort(price.begin(), price.end());
        int left = 1, right = (price.back() - price[0]) / (k - 1);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(price, k, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end
