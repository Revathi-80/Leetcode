class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastzero=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]!=0){
                nums[lastzero++]=nums[i];
            }
        }
        for(int i=lastzero;i<len;i++){
            nums[i]=0;
        }
    }
};