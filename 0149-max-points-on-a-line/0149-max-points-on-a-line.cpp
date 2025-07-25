#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return ((long long)p.first << 32) ^ (unsigned int)p.second;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int max_points = 0;
        for (int i = 0; i < n; ++i) {
            if (n - i <= max_points) break;
            unordered_map<pair<int, int>, int, pair_hash> slopeCount;
            int duplicates = 1;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy);
                }
                slopeCount[{dy, dx}]++;
            }
            int localMax = 0;
            for (auto& [slope, count] : slopeCount) {
                localMax = max(localMax, count);
            }
            max_points = max(max_points, localMax + duplicates);
        }
        return max_points;
    }
};
