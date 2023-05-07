class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_map<long long ,int>hash;
        for(int i=0;i<n;i++) {
            hash[nums[i]]++;
        }
        for(auto it :hash) {
            if(it.second==1)
                return it.first;
        }
        return 0;
    }
};