class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            int x=nums[i];
            int cnt=0;
            for(int j=0;j<n;j++) {
                if(nums[j]==x)
                    cnt++;
            }
            if(cnt==1)
                return nums[i];
        }
        return 0;
    }
};