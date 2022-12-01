class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int last=n-1,i=0;
        for(auto num:nums){
            if(num%2==0){
                ans[i++]= num;
            }
            else
                ans[last--]=num;
        }
        return ans;
    }
};