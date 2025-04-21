/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int> &answers) {
        int n = answers.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[answers[i]]++;
        }
        int ans = 0;
        for (auto &p : cnt) {
            ans +=
                (p.second + p.first) / (p.first + 1) * (p.first + 1);
        }
        return ans;
    }
};
// @lc code=end
