class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int maxSum=0;
        int minSum= INT_MAX;
        for(int i=0;i<prices.size();i++){
            minSum= min(minSum,prices[i]);
            maxSum = max(maxSum,prices[i]-minSum);
        }
        return maxSum;
    }
};