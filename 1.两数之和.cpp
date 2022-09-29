/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Cpp 的 HashMap 是 unordered_map
        unordered_map<int, int> hashTable;
        vector<int> ans(2, -1);
        // 遍历数组，将数值作为 key，下标为 value 存入哈希表，查找是否存在等于 target - i 的数
        for (int i = 0; i < nums.size(); i++) {
            auto iterator = hashTable.find(target - nums[i]);
            if (iterator != hashTable.end()) {
                // 迭代器的 first 为 key, second 为 value
                ans[0] = iterator->second;
                ans[1] = i;
            }
            hashTable[nums[i]] = i;
        }
        return ans;
    }
};
// @lc code=end
