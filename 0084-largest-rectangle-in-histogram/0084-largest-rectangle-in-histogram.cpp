class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight;
            if (i == n) {
                currHeight = 0;
            } else {
                currHeight = heights[i];
            }

            while (!stack.empty() && currHeight < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();

                int width;
                if (stack.empty()) {
                    width = i;
                } else {
                    width = i - stack.top() - 1;
                }

                int area = height * width;
                if (area > maxArea) {
                    maxArea = area;
                }
            }

            stack.push(i);
        }

        return maxArea;
    }
};
