#include<vector>
/*
 * ����
 * 1 ȷ��ԭ�����������
 * 2 ȷ��״̬
 * 3 ȷ�ϱ߽�״̬
 * 4 ״̬ת�Ʒ���
 * */
class Solution {
public:
    int climbStairs(int n) {
       std::vector<int> dp(n+3, 0);// n+3 ��ֹ����Խ�� 
	   dp[1] = 1;
	   dp[2] = 2;
	   dp[3] = 3;
	   for (int i = 3, i <= n; i++) {
   			dp[i] = dp[i-1] + dp[i-2];
   		} 
   		return dp[n];
    }
};