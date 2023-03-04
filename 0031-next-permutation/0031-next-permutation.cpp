class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
        // if(n==1) return;
        int k,i,ind;
        for( k=n-2;k>=0;k--) {
            if(nums[k]<nums[k+1]) {
                break;
            }
        }
        if(k<0 ) {
            reverse(nums.begin(),nums.end());
        }
        else {
     
        for(i=n-1;i>=0;i--) {
            if(nums[i]>nums[k]) {
                ind=i;
                break;
            }
        }
          // cout <<ind<<" "<<k;  
        swap(nums[k],nums[ind]);
        reverse(nums.begin()+k+1,nums.end());
        }
    }
};