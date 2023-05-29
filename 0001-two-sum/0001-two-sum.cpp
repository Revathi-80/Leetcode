class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n=nums.size();
      for(int i=0;i<n;i++) {
          int sum=nums[i];
          for(int j=i+1;j<n;j++) {
              if(sum+nums[j]==target) 
                  return {i,j};
          }
      }
        return {0,0};
    }
};