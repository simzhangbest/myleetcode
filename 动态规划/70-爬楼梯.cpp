#include<vector>
/*
 * 步骤
 * 1 确认原问题和子问题
 * 2 确认状态
 * 3 确认边界状态
 * 4 状态转移方程
 * */
class Solution {
public:
    int climbStairs(int n) {
       std::vector<int> dp(n+3, 0);// n+3 防止数组越界 
	   dp[1] = 1;
	   dp[2] = 2;
	   dp[3] = 3;
	   for (int i = 3, i <= n; i++) {
   			dp[i] = dp[i-1] + dp[i-2];
   		} 
   		return dp[n];
    }
};