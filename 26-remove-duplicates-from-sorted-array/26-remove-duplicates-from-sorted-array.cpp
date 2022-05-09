class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int j=0;
        for(int n:nums){
            if(!j|| n>nums[j-1]) //if !j is not included then nums[j-1] will point to nums[-1] for j=0 which does not exsits 
                nums[j++]=n;
        }
        return j;
    }
};