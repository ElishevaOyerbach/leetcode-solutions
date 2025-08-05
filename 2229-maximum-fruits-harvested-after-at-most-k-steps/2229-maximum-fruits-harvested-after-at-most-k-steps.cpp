#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = (int)fruits.size();
        int i = 0;
        long long currentSum = 0;
        long long best = 0;

        for (int j = 0; j < n; ++j) {
            currentSum += fruits[j][1];

            while (i <= j && CostToCover(fruits, startPos, i, j) > k) {
                currentSum -= fruits[i][1];
                ++i;
            }

            if (i <= j) best = max(best, currentSum);
        }

        return (int) best;
    }

    int CostToCover(const vector<vector<int>>& fruits, int startPos, int i, int j) {
        int left = fruits[i][0];
        int right = fruits[j][0];

        if (startPos <= left) {
            return right - startPos;
        } else if (startPos >= right) {
            return startPos - left;
        } else {
            int goLeftFirst = 2 * (startPos - left) + (right - startPos);
            int goRightFirst = 2 * (right - startPos) + (startPos - left);
            return min(goLeftFirst, goRightFirst);
        }
    }
};
