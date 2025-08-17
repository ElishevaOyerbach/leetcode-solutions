class Solution {
public:

 int oneNum(vector<int>& nums, int target, int first) {
    int left = first + 1;
    int right = nums.size() - 1;
    int closestSum = nums[first] + nums[left] + nums[right];

    while (left < right) {
        int currentSum = nums[first] + nums[left] + nums[right];

        if (currentSum == target) return target;

        if (abs(currentSum - target) < abs(closestSum - target)) {
            closestSum = currentSum;
        }

        if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }

    return closestSum;
}
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        sort(nums.begin(), nums.end());
        int m = nums[0] + nums[1] + nums[2];

        for(int i=0; i<n-2; i++){
            int temp = oneNum(nums,target,i);
            if (abs(temp - target) < abs(m - target)) {
                m = temp;
            }
 
        }

        return m;

    }
};