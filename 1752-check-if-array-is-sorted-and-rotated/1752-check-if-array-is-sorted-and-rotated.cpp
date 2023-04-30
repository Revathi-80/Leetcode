class Solution {
   
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int peak=0,i;
        for( i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                peak++;
            }
        }
       if(peak>1)return false;
        else
            return true;
    }
    
};