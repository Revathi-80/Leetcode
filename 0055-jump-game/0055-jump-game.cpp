class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_reach=0; //pink pointer
        for(int i=0;i<n;i++) { //red pointer
            // red pointer < pink pointer 
            // update the max position of pink pointer
            if(i<=max_reach) {
                max_reach = max(max_reach , i+nums[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }
};