class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0,n= nums.size(),i=0,j=n-1;
        while(i<=j) {
            if(nums[i]==val){
                cnt++;
                swap(nums[i],nums[j]);
                j--;
            }
            else {
                i++;
            }
        }
        return n-cnt;
    }
};