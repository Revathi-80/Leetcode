class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reached=0;
        for(int i=0;i<n;i++) {
            if(reached<i) 
                return false;
            reached= max(reached,i+nums[i]);
        }
        return true;
    }
};