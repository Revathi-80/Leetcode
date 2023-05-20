class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n=nums.size();
        int prefix=0,cnt=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++) {
            prefix+=nums[i];
            int sum=prefix-k;
            cnt+=mpp[sum];
            mpp[prefix]+=1;
           // cout<<sum<<" "<<mpp[sum]<<" "<<cnt<<endl;
        }
        return cnt;
    }
};