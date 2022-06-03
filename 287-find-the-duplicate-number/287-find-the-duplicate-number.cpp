class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size(),ans;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(auto x:mp)
            if(x.second>=2)
                ans=x.first;
        return ans;
    }
};