class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
  int product=1,n=nums.size(),cnt=0;
        for(int i=0;i<n;i++){
        if(nums[i]!=0)
            product*=nums[i];
            else
                cnt++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && cnt==0)
                nums[i]=product/nums[i];
            else if(nums[i]==0 && (cnt-1)==0)
            nums[i]=product;
            else if(nums[i]!=0 && cnt>0)
                nums[i]=0;
                
        }
        return nums;
    }
};