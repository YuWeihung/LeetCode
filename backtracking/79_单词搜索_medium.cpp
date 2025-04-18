/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    const int DIRS[4][2] = {
        { 0,  1},
        { 0, -1},
        { 1,  0},
        {-1,  0}
    };
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt[board[i][j]]++;
            }
        }
        unordered_map<int, int> word_cnt;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            word_cnt[ch]++;
            if (word_cnt[ch] > cnt[ch]) {
                return false;
            }
        }
        if (word_cnt[word[0]] > word_cnt[word.back()]) {
            reverse(word.begin(), word.end());
        }

        vector<vector<int>> visit(m, vector<int>(n));
        string path;
        auto dfs = [&](auto &&dfs, int i, int j, int k) -> bool {
            if (board[i][j] != word[k] || visit[i][j]) {
                return false;
            }
            if (k + 1 == word.size()) {
                return true;
            }
            visit[i][j] = true;
            for (auto &[dx, dy] : DIRS) {
                int x = i + dx;
                int y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n &&
                    dfs(dfs, x, y, k + 1)) {
                    return true;
                }
            }
            visit[i][j] = false;
            return false;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(dfs, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
