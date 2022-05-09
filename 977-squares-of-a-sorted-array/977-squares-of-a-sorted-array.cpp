class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        vector<int>arr(nums.size());
        for(int k=nums.size()-1;k>=0;k--){
            if(abs(nums[l])>abs(nums[r]))
                arr[k]=nums[l]*nums[l++];
            else
                arr[k]=nums[r]*nums[r--];
        }
        return arr;
    }
};