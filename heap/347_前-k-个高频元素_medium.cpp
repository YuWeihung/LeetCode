/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        };
        unordered_map<int, int> cnt;
        for (auto &x : nums) {
            cnt[x]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(cmp)>
            q(cmp);
        for (auto &[x, count] : cnt) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(x, count);
                }
            } else {
                q.emplace(x, count);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
// @lc code=end
