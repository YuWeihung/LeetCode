/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */
#include <climits>
#include <stack>
using namespace std;

// @lc code=start
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int cur_day = -1;
    StockSpanner() {
        st.emplace(-1, INT_MAX);
    }

    int next(int price) {
        cur_day++;
        while (price >= st.top().second) {
            st.pop();
        }
        int ans = cur_day - st.top().first;
        st.emplace(cur_day, price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
