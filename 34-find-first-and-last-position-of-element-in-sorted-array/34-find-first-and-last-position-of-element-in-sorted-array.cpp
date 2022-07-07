class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
       int first =-1 , last = -1;
        int n= nums.size();
        for (int i=0;i<n;i++){
            if(target!=nums[i])
                continue;
            if(first==-1)
                first=i;
            last=i;
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};