class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++) {
            mpp[nums[i]]++;
        }
        int cnt=0;
        for(auto x:mpp) {
            if(x.second ==1){
               return -1;
            }
            cnt+= ceil((double)(x.second)/3);
        }
        return cnt;
    }
};