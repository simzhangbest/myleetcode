#include <vector>
#include <stdio.h>
class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
         std::vector<int> dp;
         // 初始化dp数组， 最初所有的金额最优解为 -1 （不可达到）
         for(int i = 0; i <= amount; i++) {
         	dp.push_back(-1);
         }
         dp[0]=0;
         for(int i = 1; i <= amount; i++) {
         	for(int j = 0; j < coins.size(); j++) {
	         	if(i - coins[j] >= 0 && dp[i-coins[j]] != -1) {
	         		if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
						dp[i] = dp[i-coins[j]] + 1;
	         		}
	         	}
	         }
         }
		 return dp[amount];
    }
};


//
//class Solution {
//public:
//    int coinChange(vector<int> &coins, int amount) {
//        vector<int> amounts(amount + 1, numeric_limits<int>::max());
//        amounts[0] = 0;
//        for (int i = 0; i <= amount; ++i) {
//            if (amounts[i] != numeric_limits<int>::max()) {
//                for (const auto &coin : coins) {
//                    if (coin <= numeric_limits<int>::max() - i && i + coin <= amount) {
//                        amounts[i + coin] = min(amounts[i + coin], amounts[i] + 1);
//                    }
//                }
//            }
//        }
//        return amounts[amount] == numeric_limits<int>::max() ? -1 : amounts[amount];
//    }
//};



int main(){
	Solution solve;
	std::vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(7);
	coins.push_back(10);

	for(int i = 1; i <= 14; i++){
		printf("dp[%d] = %d\n", i, solve.coinChange(coins, i));
	}
}