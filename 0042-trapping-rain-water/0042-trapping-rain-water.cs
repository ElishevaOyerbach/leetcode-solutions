public class Solution {
    public int Trap(int[] height) {
        int water = 0;
        Stack<int> stack = new Stack<int>();
        for (int i = 0; i < height.Length; i++) {
            while (stack.Count > 0 && height[i] > height[stack.Peek()]) {
                int bottom = stack.Pop();
                if (stack.Count == 0) break;

                int distance = i - stack.Peek() - 1;
                int boundedHeight = Math.Min(height[i], height[stack.Peek()]) - height[bottom];
                water += distance * boundedHeight;
            }
            stack.Push(i);
        }
        return water;
    }
}
