class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;            
        }
        int ans=0;
        for(auto it:mpp){
            ans+=((it.second)*(it.second-1))/2;
        }
        return ans;
    }
};