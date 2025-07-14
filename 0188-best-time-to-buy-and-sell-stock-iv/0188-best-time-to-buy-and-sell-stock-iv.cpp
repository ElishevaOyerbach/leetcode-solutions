class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n ==0 || k==0)
            return 0;

        if(k>=n/2){
            int profit=0;
            for(int i=1;i<n;++i){
                if(prices[i]>prices[i-1])
                    profit+=prices[i]-prices[i-1];
            }
            return profit;
        }

        vector<vector<int>> mat(k+1,vector<int>(n,0));

        for(int t=1;t<=k;++t){
            int maxPrice = -prices[0];
            for(int i=1;i<n;++i){
                mat[t][i]= max(mat[t][i-1],prices[i]+maxPrice);
                maxPrice = max(maxPrice,mat[t-1][i]-prices[i]);
            }
        }
        return mat[k][n-1];
    }
};