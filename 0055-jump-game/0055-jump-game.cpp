class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++) {
            if(maxi>=i) {
                maxi=max(maxi,i+nums[i]);
            }
        }
        return maxi>=n-1;
    }
};