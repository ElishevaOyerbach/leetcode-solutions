class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int all_xor = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            all_xor ^= nums[i];
        }
        if(all_xor == 0){
            return true;
        }
        if(n%2==0){
            return true;
        }
        return false;

    }
};