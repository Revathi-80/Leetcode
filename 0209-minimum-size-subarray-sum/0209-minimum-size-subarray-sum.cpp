class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n=nums.size(),ans=INT_MAX;
        if(n==0) return 0;
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++){
            v[i]=v[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++){
            int find= target+v[i-1];
            auto it = lower_bound(v.begin(),v.end(),find);
            if(it!=v.end())
           ans= min(ans,int(it-(v.begin()+i-1)));
        }
        return (ans!=INT_MAX)?ans:0;
    }
};