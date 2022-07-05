class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),cnt=1,maxi=1;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
            if(nums[i]==(nums[i+1]-1))
                cnt++;
            else{
                maxi=max(cnt,maxi);
                cnt=1;
            }
            }
        }
        return max(maxi,cnt);
    }
};