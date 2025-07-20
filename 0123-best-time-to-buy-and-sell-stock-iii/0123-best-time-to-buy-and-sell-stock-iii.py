class Solution(object):
    def maxProfit(self, prices):
        if not prices:
            return 0
        k=2
        n=len(prices)

        if k >= n // 2:
            profit =0
            for i in range(1,n):
                profit+=max(prices[i] - prices[i-1],0)
            return profit

        dp = [[0] * n for _ in range(k+1)]

        for t in range(1,k+1):
            max_diff = -prices[0]
            for d in range(1,n):
                dp[t][d] = max(dp[t][d-1], prices[d] + max_diff)
                max_diff = max(max_diff, dp[t-1][d] - prices[d])
        
        return dp[k][n-1]
