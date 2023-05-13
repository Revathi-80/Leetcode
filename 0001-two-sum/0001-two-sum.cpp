class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
//         <element,index>
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++) {
            if(mpp.find(target-nums[i])!=mpp.end()) {
               for (auto it: mpp) {
                   if(it.first==(target-nums[i])) 
                       return {it.second,i};
               }
            }
            else {
                mpp[nums[i]]=i;
            }
        }
        return {0,0};
    }
};