#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> subtreeXor(n), in(n), out(n);
        int timer = 0;
        function<void(int, int)> dfs = [&](int node, int parent) {
            in[node] = ++timer;
            subtreeXor[node] = nums[node];
            for (int nei : graph[node]) {
                if (nei == parent) continue;
                dfs(nei, node);
                subtreeXor[node] ^= subtreeXor[nei];
            }
            out[node] = ++timer;
        };

        dfs(0, -1);
        int total = subtreeXor[0];
        int res = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x, y, z;
                if (in[i] > in[j] && out[i] < out[j]) {
                    x = subtreeXor[i];
                    y = subtreeXor[j] ^ subtreeXor[i];
                    z = total ^ subtreeXor[j];
                }
                else if (in[j] > in[i] && out[j] < out[i]) {
                    x = subtreeXor[j];
                    y = subtreeXor[i] ^ subtreeXor[j];
                    z = total ^ subtreeXor[i];
                }
                else {
                    x = subtreeXor[i];
                    y = subtreeXor[j];
                    z = total ^ x ^ y;
                }
                int maxVal = max({x, y, z});
                int minVal = min({x, y, z});
                res = min(res, maxVal - minVal);
            }
        }

        return res;
    }
};
