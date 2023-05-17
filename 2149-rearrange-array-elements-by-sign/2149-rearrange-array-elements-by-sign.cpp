class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
       int pos=0,neg=1;
        vector<int>arr(n);
    
        for(int i=0;i<n;i++) {
            if(nums[i]<0){
                arr[neg]=nums[i];
                neg+=2;
                }
            else {
                arr[pos]=nums[i];
                pos+=2;
            }
        }
        return arr;
    }
};