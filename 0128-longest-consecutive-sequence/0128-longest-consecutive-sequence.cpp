class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int longest=0,cnt=1,small=INT_MIN;
        for(int i=0;i<n;i++) {
           if(nums[i]-1 == small) {
               small=nums[i];
               cnt++;
           }
            else if (nums[i]!=small) {
                small=nums[i];
                cnt=1;
            }
            longest=max(cnt,longest);
        }
        return longest;
    }
};