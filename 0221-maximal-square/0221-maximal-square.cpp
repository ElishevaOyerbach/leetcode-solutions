#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> dp(cols, 0);
        int maxSide = 0;
        int prev = 0; 

        for (int i = 0; i < rows; ++i) {
            prev = 0; 
            for (int j = 0; j < cols; ++j) {
                int temp = dp[j]; 
                if (matrix[i][j] == '1') {
                    int minVal = dp[j]; 
                    if (j > 0) {
                        if (dp[j - 1] < minVal) {
                            minVal = dp[j - 1];
                        }
                        if (prev < minVal) {
                            minVal = prev;
                        }
                    }
                    else {
                        minVal = 0;
                    }
                    dp[j] = minVal + 1;
                    if (dp[j] > maxSide) {
                        maxSide = dp[j];
                    }
                }
                else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxSide * maxSide;
    }
};
