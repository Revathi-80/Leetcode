class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ele=nums[0];
        for(int i=0;i<n;i++) {
            if(cnt==0) {
                ele=nums[i];
                cnt++;
            }
            else if(nums[i]==ele) {
                cnt++;
            }
            else 
                cnt--;
        }
        return ele;
    }
};