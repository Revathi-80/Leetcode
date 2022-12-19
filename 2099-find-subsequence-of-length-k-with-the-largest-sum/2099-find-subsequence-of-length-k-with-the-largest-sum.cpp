class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       vector<int>v;
        int n=nums.size();
        int i=0,t=k;
        while(t--) {
            v.push_back(nums[i]);
            i++;
        }
        for(int j=i;j<n;j++) {
            int mini=min_element(v.begin(),v.end())-v.begin();
            if(v[mini] < nums[j]) {
                v.erase(v.begin()+mini);
                v.push_back(nums[j]);
            }
            
        }
        return v;
    }
};